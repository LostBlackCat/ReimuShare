import numpy
import time
a=numpy.random.rand(1000000)
b=numpy.random.rand(1000000)

tic=time.time()
c=numpy.dot(a,b)
toc=time.time()
print("Cactorized version:"+str(1000*(toc-tic)))

te=[-1,-2,3,4]
zb=abs(te)
print(zb)