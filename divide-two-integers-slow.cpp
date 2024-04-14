#include <climits>
#include <math.h>
class Solution {
public:
    int divide(int dividend, int divisor) {
        int result = 0;
        int sum = 0;

        const bool negRes = (dividend ^ divisor) < 0;
        const int add = negRes ? -1 : 1;
        const int limit = negRes ? 0x80000000 : 0x7FFFFFFF;


        // Overflowing only occur when dividend is min_int and divisor is -1
        if(dividend==0x80000000 && divisor==-1)
            return 0x7FFFFFFF;
        
        // Make sure dividend and divisor has the same sign
        if(negRes) {
            if(dividend < 0)
                divisor = -divisor;
            else if (divisor < 0)
                dividend = -dividend;
        }
        if(divisor == 1 || divisor == -1) {
            return negRes ? dividend : abs(dividend);
        }
        if(dividend == divisor) {
            return negRes ? -1 : 1;
        }
        
        // Number of bits in divisor
        if(!(dividend == 0x80000000 || divisor == 0x80000000)) {
            int bits = 0;
            int log2 = -1;

            int x = divisor;
            int y = dividend;
            // Handle negative numbers
            if (negRes) {
                x = -x;
                y = -y;
            }
            for(; x && bits<=1; x>>=1) {
                bits += (x & 1);
                log2++;
            }
            if (bits == 1 && log2 > 0) { // Is a power of two
                return negRes ? -(y>>log2) : y >> log2;
            }
        }


        while(true) {
            dividend -= divisor;
            if((divisor>0 && dividend<0) || (divisor<0 && dividend>0))
                return result;
            result += add;
        }
    }
};
