#include <cctype>
#include <string>
#include <cmath>

using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        const int NUM_MAX = pow(2, 31)-1;
        const int NUM_MIN = pow(-2, 31);
        long num = 0;
        int i = s.find_first_not_of(" ");
        bool negative = false;
        if(i>=s.length())
            return 0;
        if(s[i] == '-') {
            negative = true;
            i++;
        }
        else if(s[i] == '+')
            i++;
        if(i>=s.length())
            return 0;
        for(; s[i] >= 48 && s[i] <= 57; i++) {
            num = (long)num*10+(s[i]-48);
            if(!negative && num > NUM_MAX) {
                return NUM_MAX;
            } else if (negative && num*-1 < NUM_MIN){
                return NUM_MIN;
            }
        }
        if(negative) {
            num *= -1;
        }
        return (int)num;
    }
};
