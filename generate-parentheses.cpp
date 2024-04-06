#include <string>
#include <vector>
#include <unordered_set>
class Solution {
    vector<string> insertParentheses(string s) {
        // The algorithms is: you can insert an open parenthesis in every position, but you can only close that parenthesis at positions where the stack (open parentheses - closing parentheses) is equal to the stack at the open parenthesis position
        // The algorithms is: you can insert an open parenthesis in every position, but only insert a closing parenthesis in positions after the opening one

        unordered_set<string> combinations;

        for(int i = 0; i <= s.length(); i++) {
            string newCombinationTemplate = s;
            newCombinationTemplate.insert(i, "(");
            for(int j = i+1; j<=s.length(); j++) {
                string newCombination = newCombinationTemplate;
                newCombination.insert(j, ")");
                combinations.insert(newCombination);
            }
        }
        return vector<string>(combinations.begin(), combinations.end());
    }
public:
    vector<string> generateParenthesis(int n) {
        set<string> combinations = {"()"};
        
        for(int i = 1; i < n; i++) {
            set<string> newCombinations;
            for(auto combination : combinations) {
                for(auto newCombination : insertParentheses(combination)) {
                    newCombinations.insert(newCombination);
                }
            }
            combinations = newCombinations;
        }
        return vector<string>(combinations.begin(), combinations.end());
    }
};
