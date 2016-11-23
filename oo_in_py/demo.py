# When I import this module the process is goin to be called demo
import numpy as np
import matplotlib.pyplot as plt

class Function:
    def __init__(self):
        self.dim_dommain = 1
        self.dim_codomain = 1
        print "hello from constructor!"
        self.domain = np.array([])
        self.codomain = np.array([])
        return
    def evaluate(self):
        print "provide implementation"
        #raise NotImplementedError()
    def plot(self):
        plt.plot(self.domain, self.codomain)
        plt.show()

    def say_hello(self):
        print "say hello!"

class Parabola(Function): # Questa classe ereditta da Function
    def __init__(self, a, b, c):
        # y = a x^2 + b x + c
        self.a = a
        self.b = b
        self.c = c

    def evaluate(self, x):
        self.domain = x
        y = self.a * x**2 + self.b * x + self.c
        self.codomain = y
        return y

#if __name__ == "demo": # Check when called with main
if __name__ == "__main__":
    #func = Function()
    #func.say_hello()  # you should read as func.say_hello(func)... this is why you need self
    #func.evaluate()

    func1 = Parabola(3,2,1)
    func1.evaluate(np.linspace(0,1))
    func1.plot()
    print "hello from demo"
