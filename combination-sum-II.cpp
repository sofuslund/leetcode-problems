#include <bits/stdc++.h>
using namespace std;
class Solution {
    vector<vector<int>> helper(vector<int>& candidates, int target, int sum, vector<int> solution, int idx) {
        vector<vector<int>> solutions;
        for(int i = idx+1; i < candidates.size(); i++) {
            if(i > idx+1 && candidates[i-1] == candidates[i])
                continue;
            if(sum + candidates[i] < target) {
                auto tmp = solution;
                tmp.push_back(candidates[i]);
                auto new_solutions = helper(candidates, target, sum+candidates[i], tmp, i);
                solutions.insert(solutions.end(), new_solutions.begin(), new_solutions.end());
            } else if(sum + candidates[i] > target) {
                continue;
            } else {
                auto tmp = solution;
                tmp.push_back(candidates[i]);
                solutions.push_back(tmp);
            }
        }
        return solutions;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        return helper(candidates, target, 0, {}, -1);
    }
};
