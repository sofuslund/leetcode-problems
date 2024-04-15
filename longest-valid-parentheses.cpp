class Solution {
    int val(char c) {
        if(c=='(')
            return 1;
        return -1;
    }
public:
    int longestValidParentheses(string s) {
        int max = 0;
        for(int i = 0; i < s.size(); i++) {
            int sum = 0;
            for(int j = i; j < s.size(); j++) {
                sum += val(s[j]);
                if(sum <= -1)
                    break;
                if(sum == 0 && j-i+1 > max)
                    max = j-i+1; // Length of substring
            }
        }
        return max;
    }
};
