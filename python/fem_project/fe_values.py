class FEValues(object):
    def __init__(self,fe,quad,mapping):
        self.__fe = fe
        self.__quad = quad
        self.__map = mapping

    def reinit(self,cell):
        self.__cell = cell

    def get_basis_values_derivatives(self):
        return

    def get_basis_values(self):
        return

    def get_quadrature_weights(self):
        return

    def get_quadrature_points(self):
        return
