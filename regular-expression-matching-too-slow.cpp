class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0;
        for (; i < p.size(); i++) {
            if ((i+1<p.size() && p[i+1] == '*')) {
                if (i+2==p.size()) { // * is last char in pattern
                    if (i >= s.size()) // There are not more chars to match in s
                        return true;
                    else if(p[i] == '.' && i+2==p.size()) // Last part of pattern is .*
                        return true;
                }
                    
                string remainingPattern = p.substr(i+2, p.size()-i-2);

                
                for (int j = 0; i+j <= s.size(); j++) {
                    string remainingString = "";
                    if(i+j!=s.size())
                        remainingString = s.substr(i+j, s.size()-i-j);
                    
                    if(isMatch(remainingString, remainingPattern)) {
                        return true;
                    }
                    
                    // Makes sure j characters matches p[i] if p[i] is not .
                    if(p[i] != '.' && i+j<s.size() && s[i+j] != p[i])
                        break;
                }
                return false;
            } if(i >= s.size()) {
                return false;
            } else if (p[i] != '.' && s[i] != p[i]) {
                return false;
            }
            
        }
        if (i<s.size())
            return false;
        return true;
    }
};
