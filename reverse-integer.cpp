#include <cstdint>
#include <cmath>
#include <iostream>
#include <iomanip>

// 0 MS RUNTIME, my solution beats 100% of C++ users

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int32_t old_x = x;
        int32_t new_x = 0;
        for(int i = 0; (x>0 && old_x>0) || (x<0 && old_x < 0); i++) {
            int32_t x_rightmost_digit = (old_x-int(old_x/10)*10);
            // If there will be overflow 
            if((x>0 && new_x > (((pow(2,31)-1)-x_rightmost_digit)/10)) || (x<0 && new_x < ((pow(-2,31)-x_rightmost_digit)/10))) {
                return 0;
            }
            new_x = new_x * 10 + x_rightmost_digit;
            old_x /= 10;
        }
        cout << "New x: " << new_x << endl; // 2147483641
        return new_x;
    }
};
