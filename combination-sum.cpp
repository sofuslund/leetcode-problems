 class Solution {
    void helper(vector<int>& cands, vector<vector<int>>& solutions, int k, int sum, vector<int>& solution, int idx) {
        for(int i = idx; i < cands.size(); i++) {
            if(sum+cands[i] > k) 
                continue;
            else if (sum+cands[i] < k){
                solution.push_back(cands[i]);
                helper(cands, solutions, k, cands[i]+sum, solution, i);
                solution.pop_back();
            } else {
                solution.push_back(cands[i]);
                solutions.push_back(solution);
                solution.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tmp;
        vector<vector<int>> solutions;
        helper(candidates, solutions, target, 0, tmp, 0);
        return solutions;
    }
};
