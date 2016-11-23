import numpy as np
import numpy.polynomial.polynomial as poly

class FiniteElement(object):

    def __init__(self,fe_in):

        Nk = construct_dual_basis()
        Pk = construct_poly(deg)

        C = construct_cij(Nk,Pk)
        self.__V = construct_canonical_basis(C)


    def get_num_basis(self):
        return self.get_degree()+1


    def get_basis_values(self, q):
        vv = np.zeros((len(V), len(q)))
        for i in range(len(V)):
            vv[i] = V[i](q)
        return vv


    def get_basis_values_derivatives(self, q):
        vv = np.zeros((len(V), len(q)))
        for i in range(len(V)):
            vv[i] = V[i].deriv()(q)
        return vv


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


