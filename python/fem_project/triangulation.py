import numpy as np

class Triangulation(object):
    def discretise(self):
        n = 2**self.__global_refinement+1
        self.__x = np.linspace(0,1,n)

    def __init__(self, initial_refinement):
        self.__global_refinement = initial_refinement
        self.discretise()

    def get_n_vertices(self):
        return len(self.__x)

    def get_n_elements(self):
        return len(self.__x) -1

    def get_vertex_list(self):
        return self.__x 

