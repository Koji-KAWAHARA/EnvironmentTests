import numpy as np

class Message():
    def __init__(self, message):
        self.value = message


"""Indent has some meaning! This time, scope of class definition."""
myinstance = Message("Hello!")
print(myinstance.value)

A = np.arange(4).reshape((2, 2))
B = np.arange(4).reshape((2, 2))
v = np.arange(2)

print(np.matmul(A, B))
print(np.matmul(A, v))
print(np.dot(A, v))
e2 = ([1]*(9-1)+[0])*9
print(e2)
