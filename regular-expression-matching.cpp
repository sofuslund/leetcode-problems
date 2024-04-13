class Solution {
public:
    bool isMatch(string s, string p) {
        bool dp[21][21];
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;

        
        for(int i = 0; i < s.size(); i++) {
            for(int j = 0; j < p.size(); j++) {
                if (j+1 < p.size() && p[j+1] == '*') {
                    if (p[j] == '.') {
                        if(dp[i][j])
                            dp[i][j+1] = true;
                        dp[i+1][j+1] = dp[i][j] || dp[i][j+1] || dp[i+1][j];
                    } else {
                        if(dp[i][j])
                            dp[i][j+1] = true;
                        dp[i+1][j+1] = ((dp[i][j+1] || dp[i][j]) && p[j] == s[i]) || dp[i+1][j];
                    }
                } else if (p[j]=='*') { // Row should be copied
                    if(i == 0)
                        dp[0][j+1] = dp[0][j];
                    dp[i+1][j+1] = dp[i+1][j];
                }
                else {
                    dp[i+1][j+1] = dp[i][j] && (p[j]=='.'||p[j]==s[i]);
                }
            }
        }
        cout << "    ";
        for(int i = 0; i < s.size(); i++) {
            cout << s[i] << " ";
        }
        cout << endl;
        for(int i = 0; i <= p.size(); i++) {
            if(i-1>=0)
                cout << p[i-1] << ": ";
            else
                cout << "   ";
            for(int j=0;j<=s.size();j++) {
                cout << dp[j][i] << " ";
            }
            cout << endl;
        }

        return dp[s.size()][p.size()];
    }
};
