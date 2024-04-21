#include <bits/stdc++.h>
using namespace std;
class Solution {
    void helper(vector<int>& candidates, vector<vector<int>>& solutions, int target, int sum, vector<int>& solution, int idx) {
        for(int i = idx; i < candidates.size(); i++) {
            // To prevent duplicate solutions, only generate solutions for the lowest index element when there are multiple of the same candidates
            if(i > idx && candidates[i-1] == candidates[i])
                continue;
            if(sum + candidates[i] < target) {
                solution.push_back(candidates[i]);
                helper(candidates, solutions, target, sum+candidates[i], solution, i+1);
                solution.pop_back();
            } else if(sum + candidates[i] > target) {
                continue;
            } else {
                solution.push_back(candidates[i]);
                solutions.push_back(solution);
                solution.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> solution_stack;
        vector<vector<int>> solutions;
        helper(candidates, solutions, target, 0, solution_stack, 0);
        return solutions;
    }
};
