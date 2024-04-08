#include <vector>
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> newNums;
        newNums.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if(nums[i] != nums[i-1])
                newNums.push_back(nums[i]);
        }

        nums = newNums;
        return newNums.size();
    }
};
