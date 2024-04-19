class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int stop = nums.size()-1;
        
        while(stop-start>=0) {
            int k = start + (stop-start+1)/2;

            if(nums[k] == target)
                return k;
            if(nums[k] <= nums[stop]) {
                if(nums[k] < target && target <= nums[stop]) {
                    start = k+1;
                } else {
                    stop = k-1;
                }
            } else {
                if(nums[start] <= target && target < nums[k]) {
                    stop = k-1;
                } else  {
                    start = k+1;
                }
            }
        }
        return -1;
    }
};
