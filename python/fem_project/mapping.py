import numpy as np

class Mapping(object):
    def __init__(self, vertices):
        self.__x = vertices

    def get_element_jacobian(self,element):
        assert( element < len(self.__x) - 1 )
        return self.__x[element] - self.__x[element+1]

    def get_element_vertex(self,element):
        assert( element < len(self.__x) - 1 )
        return self.__x[element]

    def map_points(self,element,ref_x):
        return get_element_vertex(element)
               + get_element_jacobian(element) * ref_x

