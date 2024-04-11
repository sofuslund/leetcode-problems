class Solution {
public:
    int strStr(string haystack, string needle) {
        // Compute KMP table
        int matchTable[needle.size()];
        memset(matchTable, 0, sizeof(matchTable));
        int lps = 0; // Longest prefix that is also a suffix for i length
        for (int i = 1; i < needle.size(); i++) {
            if(needle[lps]==needle[i]) { // Lps continues and increases by one
                lps++;
            } else { // Lps is smaller
                while(lps > 0) {
                    bool b = true;
                    for (int j = 0; j < lps; j++) {
                        if (needle[j] != needle[i-lps+1+j])
                            b = false;
                    }
                    if(b)
                        break;
                    lps--;
                }
            }
            matchTable[i] = lps;
        }
        int count = 0;
        for (int i = 0; i < haystack.size(); i++) {
            comparison:
            if(haystack[i] == needle[count]) {
                count++;
            } else {
                if (count>0) {
                    count = matchTable[count-1];
                    goto comparison;
                }
            }
            if(count == needle.size())
                return i-count+1; // Where match starts
            
        }

        return -1;
    }
};
