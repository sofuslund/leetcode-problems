#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;
        vector<int> v(2);
        for(int i = 0; i < nums.size(); i++) {
            if(hashmap.find(target - nums[i]) != hashmap.end()) {
                v[0] = i;
                v[1] = hashmap[target - nums[i]];
                return v;
            }
            hashmap[nums[i]] = i;
        }
        return v;
    }
};
