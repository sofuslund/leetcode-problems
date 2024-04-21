class Solution {
    vector<vector<int>> helper(vector<int>& cands, int k, int sum, vector<int> solution) {
        vector<vector<int>> solutions;
        for(int cand : cands) {
            if(solution.size()>= 1 && cand<solution[solution.size()-1]) // We are only using sorted solutions so that we guarantee the same solution is not used twice
                continue;
            if(sum+cand > k) 
                continue;
            else if (sum+cand < k){
                auto tmp = solution;
                tmp.push_back(cand);
                auto sols = helper(cands, k, cand+sum, tmp);
                solutions.insert(solutions.end(), sols.begin(), sols.end());
            } else {
                auto tmp = solution;
                tmp.push_back(cand);
                solutions.push_back(tmp);
            }
        }
        return solutions;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        return helper(candidates, target, 0, vector<int>());
    }
};
