#include <climits>
#include <cmath>
#include <iostream>
class Solution {
    int neg(int n) {
        if(n<=0)
            return n;
        else
            return -n;
    }
public:
    int divide(int dividend, int divisor) {
        bool dividendMin = false;
        const int min = 0x80000000;
        const int max = 0x7FFFFFFF;
        const bool negative = (dividend ^ divisor) < 0;

        if(divisor == 1 || divisor == -1) {
            if(!negative && dividend == min)
                return max;
            return negative ? neg(dividend) : abs(dividend);
        }
        if(divisor == dividend) {
            return negative ? -1 : 1;
        }

        if(dividend == min) {
            dividend = max;
            dividendMin = true;
        }
        dividend = abs(dividend);
        divisor = abs(divisor);

        int result = 1;
        int sum = divisor;
        if(sum>dividend)
            return 0;
        while(sum<=(max >> 1) && (sum << 1) <= dividend) {
            sum <<= 1;
            result <<= 1;
        }


        while(sum<=max-divisor && sum+divisor <= dividend) {
            sum += divisor;
            result++;
        }

        if(dividendMin) {
            if(-sum>=min+divisor) {
                result++;
            }
        }
        return negative ? -result : result;
    }
};
