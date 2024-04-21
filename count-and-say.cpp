#include <vector>
#include <string>
class Solution {
    vector<string> say = {"1"};
public:
    string countAndSay(int n) {
        cout << n << endl;
        if(n<=say.size()) {
            return say[n-1];
        } else {
            string tmp = countAndSay(n-1);
            string ans;
            cout << tmp << endl;
            for(int i = 0; i < tmp.size(); i++) {
                int count = 1;
                while(i+1<tmp.size() && tmp[i] == tmp[i+1]) {
                    count++;
                    i++;
                }
                string s = {char(count+'0'), tmp[i]};
                cout << s << endl;
                ans.append(s);
            }
            say.insert(say.begin()+n-1, ans);
            return ans;
        }
    }
};
