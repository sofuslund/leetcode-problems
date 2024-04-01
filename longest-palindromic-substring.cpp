class Solution {
public:
    string longestPalindrome(string s) {
        string palindrome = "";
        for (int i = 0; i < s.length(); i++) {
            int j = i, k = i;
            // Check for odd number length palindromes
            while (j - 1 >= 0 && k + 1 < s.length() && s.at(j - 1) == s.at(k + 1)) {  
                j--;
                k++;
            }
            if (k - j + 1 >= palindrome.length())
                palindrome = s.substr(j, k-j + 1);
            j = i; k = i;
            // Check for even number length palindromes
            if (i+1 < s.length() && s.at(i) == s.at(i+1)) {
                k = i+1;
                while (j - 1 >= 0 && k + 1 < s.length() && s.at(j - 1) == s.at(k + 1)) {  
                    j--;
                    k++;
                }
                if (k - j + 1 >= palindrome.length())
                    palindrome = s.substr(j, k-j + 1);
            }

        }
        return palindrome;
    }
};
