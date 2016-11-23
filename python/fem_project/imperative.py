import numpy as np
import matplotlib.pyplot as plt
import numpy.polynomial.polynomial as poly

from numpy.polynomial.legendre import leggauss

def construct_dual_basis():
    N = []
    N.append(lambda f: f(0.))
    #N.append(lambda f: f(1./3))
    #N.append(lambda f: f(.5))
    #N.append(lambda f: f(2./3))
    N.append(lambda f: f(1.))
    return N

def construct_poly(deg):
    E = []
    for i in range(deg+1):
        c = np.zeros((i+1,))
        c[-1] = 1
        E.append(poly.Polynomial(c))
    return E

def construct_cij(N,P):
    C = np.zeros((0,len(N))) # Matrix for the change of variables
    for dof in N:
        row = np.array([])
        for p in P:
            row = np.hstack((row,[dof(p)]))
        C = np.vstack((C,row))
    return C

def construct_canonical_basis(C):
    V = []
    for k in range(C.shape[0]):
        delta_ij = np.zeros((C.shape[0],))
        delta_ij[k] = 1. # delta_ik
        vk = np.linalg.solve(C, delta_ij)
        V.append(poly.Polynomial(vk)) # Construct the basis using the right coefficients of the polynomials
    return V

def apply_matrx_bc(A):
    ck = A[0,0]
    A[0] = 0
    A[0,0] = ck

    ck = A[-1,-1]
    A[-1] = 0
    A[-1,-1] = ck

def apply_rhs_bc(rhs):
    rhs[0] = 0
    rhs[-1] = 0

def assemble_system(x,V,myf):

    h = 1./(len(x)-1)

    degree = 2*len(V)-1
    q,w = leggauss(degree) # Gauss between -1 and 1
    q = (q+1)/2 # Go back to 0,1
    w = w/2

    Vq = np.zeros((len(V), len(q)))
    Vpq = np.zeros((len(V), len(q)))

    for i in range(len(V)):
        Vq[i] = V[i](q)
        Vpq[i] = V[i].deriv()(q)

    n_dofs = (len(x)-1)*(len(V)-1)+1

    A = np.zeros((n_dofs, n_dofs))
    M = np.zeros((n_dofs, n_dofs))
    rhs = np.zeros((n_dofs,))

    # Construct the local matrix only once:

    local_A = np.einsum('jq, iq, q -> ij', Vpq/h, Vpq/h, w*h)
    local_M = np.einsum('jq, iq, q -> ij', Vq, Vq, w*h)

    print Vpq
    print local_A

    for i in range(len(x)-1):
        start = i*(len(V)-1)
        end = start+len(V)

        index = range(start, end)
        A[np.ix_(index, index)] += local_A
        M[np.ix_(index, index)] += local_M

        # The transformation of the quadrature points
        xq = x[i]+h*q
        local_rhs = np.einsum('iq, q, q -> i', Vq, w*h, myf(xq))

        rhs[index] += local_rhs

    # Fix the boundary conditions
    apply_matrx_bc(A)
    apply_matrx_bc(M)
    apply_rhs_bc(rhs)

    return A,M,rhs

def evaluate_l2_error(x,V,u,exact_sol):
    h = 1./(len(x)-1)

    degree = 4*(2*len(V)-1)
    q,w = leggauss(degree) # Gauss between -1 and 1
    q = (q+1)/2 # Go back to 0,1
    w = w/2

    Vq = np.zeros((len(V), len(q)))

    for i in range(len(V)):
        Vq[i] = V[i](q)


    error = 0.

    for i in range(len(x)-1):
        start = i*(len(V)-1)
        end = start+len(V)

        index = range(start, end)
        xq = x[i]+h*q

        fem_sol_k = np.einsum('i,iq -> q', u[index],Vq)
        exact_sol_k = exact_sol(xq)

        sq_error = (np.abs(exact_sol_k-fem_sol_k))**2.

        error += np.sum(sq_error*w)#np.einsum('i,i', sq_error,w)

    return np.sqrt(error)

def evaluate_h1_error(x,V,u,exact_sol_der):
    h = 1./(len(x)-1)

    degree = 4*(2*len(V)-1)
    q,w = leggauss(degree) # Gauss between -1 and 1
    q = (q+1)/2 # Go back to 0,1
    w = w/2

    Vq = np.zeros((len(V), len(q)))
    Vpq = np.zeros((len(V), len(q)))

    for i in range(len(V)):
        Vq[i] = V[i](q)
        Vpq[i] = V[i].deriv()(q)

    error = 0.

    for i in range(len(x)-1):
        start = i*(len(V)-1)
        end = start+len(V)

        index = range(start, end)
        xq = x[i]+h*q

        fem_sol_k = np.einsum('i,iq -> q', u[index],Vpq/h)
        exact_sol_k = exact_sol_der(xq)

        sq_error = (np.abs(exact_sol_k-fem_sol_k))**2.

        error += np.sum(sq_error*w)#np.einsum('i,i', sq_error,w)

    return np.sqrt(error)

if __name__ == "__main__":
    p = lambda p : p(0)
    f = lambda x : x

    Nk = construct_dual_basis()

    print Nk
    print Nk[0](f)
    print Nk[1](f)

    deg = 1

    Tk = np.array([0,1])
    Nk = construct_dual_basis()
    Pk = construct_poly(deg)
    print Pk

    C = construct_cij(Nk,Pk)

    print C

    V = construct_canonical_basis(C)

    s = np.linspace(0,1,1025)
    #for v in V:
    #    plt.plot(s, v(s))
    #plt.show()

    import sympy as sym
    t = sym.var('t')
    sol = sym.sin(sym.pi*t)#(t-1)*t**2#sym.sin(2*sym.pi*t)
    sol_der = sym.diff(sol,t,1)
    force = -1*sym.diff(sol,t,2)

    dx = []
    l2_err = []
    h1_err = []

    exact_sol = sym.lambdify(t, sol, 'numpy')#lambda x: np.sin(2*np.pi*x)
    exact_sol_der = sym.lambdify(t, sol_der, 'numpy')
    myf = sym.lambdify(t, force, 'numpy')#lambda x: 4*np.pi**2*np.sin(2*np.pi*x)

    for n in range(2,3):

        n=n**2+1

        x=np.linspace(0,1,n)

        A2, M, rhs = assemble_system(x,V,myf)
        print A2
        print rhs

        # Solve the system
        """sys_m = A2
        ufem = np.linalg.solve(sys_m, rhs)

        l2_err.append(evaluate_l2_error(x,V,ufem,exact_sol))
        h1_err.append(evaluate_h1_error(x,V,ufem,exact_sol_der))

        dx.append(1./(len(x)-1))

        #plt.loglog(dx,l2_err)
        #plt.loglog(dx,np.array(dx)**1.5)
        plt.loglog(dx,h1_err)
        plt.loglog(dx,np.array(dx)**.5)

    plt.show()"""
