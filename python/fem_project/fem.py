import numpy as np
import matplotlib.pyplot as plt

from numpy.polynomial.legendre import leggauss

from finite_element import FiniteElement
from triangulation import Triangulation
from dof_handler import DofHandler
from mapping import Mapping
from quadrature import QGauss
from fe_values import FEValues



if __name__ == "__main__":
