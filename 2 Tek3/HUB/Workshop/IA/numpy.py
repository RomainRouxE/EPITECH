import numpy as np
import math

# custom function
def sigmoid(x):
  return 1 / (1 + math.exp(-x))

x = np.array([ -0.54761371,  17.04850603,   4.86054302])
print (sigmoid(x))