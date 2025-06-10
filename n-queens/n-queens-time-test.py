# This document is made to test the time it takes to run the N-Queens problem with different estimations of the number of iterations
# To see if my idea for a solution is efficient enough for n=9

# Estimations of the number of iterations for n=9
# 81*56*36*22*11*2
# 81*56*36*22*13*9*4
# Max: 9*7*5*4*4*4*3*2*2
# Realistic:9*7*5*4*3*3*2*2*1

# After creating the solution I calculated the actual number of leaves visited in the search tree for n=9 to be 2936
# Which I figured was close to 9*6*6*3*3, which maybe can help show the average number of possibilities each row (It is not the actual average possibilities each row, just a guess)

from math import *
x = 1
for i in range(9*7*5*4*3*2*2*2*1):
    x *= 2