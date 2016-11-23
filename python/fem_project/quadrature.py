from numpy.polynomial.legendre import leggauss

class QGauss(object):
    def __init__(self,degree):
        q,w = leggauss(degree) # Gauss between -1 and 1
        self.__q = (q+1)/2 # Go back to 0,1
        self.__w = w/2
    def get_ref_points(self):
        return self.__q
    def get_ref_weights(self):
        return self.__w
