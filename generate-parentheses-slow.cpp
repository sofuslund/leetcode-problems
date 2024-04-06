#include <string>
#include <vector>
#include <iostream>
class Solution {
    bool isValid(string s) {
        map<char, char> closingToOpeningBracket = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        string openBrackets = "";
        for(char c : s) {
            if (string("([{").find(c) != string::npos)
                openBrackets.push_back(c);
            else if(openBrackets.length()==0) // If there'is a closing bracket without an opening one
                return false;
            else if(closingToOpeningBracket[c]!=openBrackets[openBrackets.length()-1]) // If the closing brakcet is not equal to the last opened bracket
                return false;
            else // The closing bracket matches the last opening bracket
                openBrackets.pop_back();
        }
        if(openBrackets.length() != 0)
            return false;
        return true;
    }
public:
    vector<string> combinationsOf(int n) {
        vector<string> combinations;
        if(n == 1) {
            return vector<string>{"(", ")"};
        }
        vector<string> tmp = combinationsOf(n-1);
        for(auto combination : tmp) {
            combinations.push_back("(" + combination);
        }
        for(auto combination : tmp) {
            combinations.push_back(")" + combination);
        }
        return combinations;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> validCombinations;

        string parentheses(n, '(');
        parentheses.append(string(n, ')'));

        cout << parentheses << endl;
        vector<string> combinations = combinationsOf(n*2);
        for (auto combination : combinations) {
            if(isValid(combination)) {
                validCombinations.push_back(combination);
            }
        }

        return validCombinations;
    }
};
