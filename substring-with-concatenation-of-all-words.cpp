#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> positions;
        const int wordLen = words[0].length();
        const int permLen = words.size() * wordLen;

        unordered_map<string,int> initialWordsMap;
        for (auto word : words) {
            if (initialWordsMap.find(word) != initialWordsMap.end())
                initialWordsMap[word]++;
            else
                initialWordsMap[word] = 1;
        }
        if (s.length() < permLen)
            return positions;

        // Sliding window iteration
        string curr = s.substr(0, permLen);
        int i = 0;
        for (int i = 0; i+permLen-1 < s.length(); i++) {
            auto wordsMap = initialWordsMap;
            // cout << s.substr(i, permLen) << endl;
            
            bool perm = true;
            for (int j = i; j < i+permLen; j += wordLen) {
                auto count = wordsMap.find(s.substr(j, wordLen));
                if (count == wordsMap.end() || count->second == 0) {
                    perm = false;
                    break;
                }
                count->second--;
            }
            if(perm) {
                positions.push_back(i);
            }
        }
        return positions;
    }
};
