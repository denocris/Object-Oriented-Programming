from triangulation import Triangulation
from finite_element import FiniteElement


class DofHandler(object):
    def __init__(self, t_in):
        self.__tria
        self.__element # index of the current element

    def __iter__(self):
        return self

    def setup_dofs_numbering(self, fe_in):

    def local_to_global_indeces(self):
        return

    def get_n_dofs(self):
        return

    def get_n_elements(self):
        return

    def get_elem_id(self):
        return

    def next(self):
        if self.__element < (self.get_n_elements()-1):
            self.__element+=1
            return self
        else:
            raise StopIteration()
