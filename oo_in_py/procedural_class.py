import numpy as np
import matplotlib.pyplot as plt

class Function:
    def __init__(self):
        self.dim_dommain = 1
        self.dim_codomain = 1
        self.domain = np.array([])
        self.codomain = np.array([])
        return

    def plot(self):
        plt.plot(self.domain, self.codomain)
        #plt.show()


class Parabola(Function): # Questa classe ereditta da Function
    def __init__(self, a, b, c):
        # y = a x^2 + b x + c
        self.a = a
        self.b = b
        self.c = c
        return

    def evaluate(self, x, y):
        self.domain = x
        y = self.a * x**2 + self.b * x + self.c
        self.codomain = y
        return y

class Ellipse(Function): # Questa classe eredita da Function
    def __init__(self, a, b, s):
        Function.__init__(self)
        self.a = a
        self.b = b
        self.s = s
        return

    def evaluate(self, domain, codomain):
        e1 = 1. - ((domain - self.s)/self.a)**2
        pos_entries = np.where(e1 > 0)
        self.domain = domain[pos_entries]
        self.codomain = self.b * np.sqrt(e1[pos_entries])
        return e1

#if __name__ == "demo": # Check when called with main
if __name__ == "__main__":
    #func = Function()
    #func.say_hello()  # you should read as func.say_hello(func)... this is why you need self
    #func.evaluate()

    x = np.linspace(-1,1)
    y = np.array([])

    func1 = Parabola(1,3,2)
    func1.evaluate(x,y)
    func1.plot()

    func2 = Parabola(1,-3,2)
    func2.evaluate(x,y)
    func2.plot()

    func3 = Parabola(4,-16.8,17.2)
    func3.evaluate(x,y)
    func3.plot()

    func4 = Ellipse(1, 20,1.5)
    func4.evaluate(x,y)
    func4.plot()

    plt.show()
    print "hello from demo"
