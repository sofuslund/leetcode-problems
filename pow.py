class Solution:
    def myPow(self, x: float, n: int) -> float:
        def rec(x, n):
            if n == 0:
                return 1
            if n == 1:
                return x

            half = rec(x, n//2)
            if n % 2 == 0:
                return half * half
            return half * half * x

        if x == 0:
            return 0
        
        res = rec(x, abs(n))
        if n < 0:
            return 1/res
        return res
