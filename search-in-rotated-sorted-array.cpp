class Solution {

public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==1)
            return nums[0] == target ? 0 : -1;
        int start = 0;
        int stop = nums.size()-1;
        // In the end k should be where k-1 is not smaller than k
        int k = 0;
        int prev_k = 0;
        while(stop-start>=0) {
            prev_k = k;
            k = start + (stop-start+1)/2;
            cout << k << endl;
            if(nums[k]>nums[prev_k]) {
                start = k;
            } else if (nums[k]<nums[prev_k]) {
                stop = k;
            } else {
                break;
            }
        }
        if(nums[k]>nums[k-1]) { // There was no rotation
            start = 0;
            stop = k;
        }
        else if(target>=nums[0]) {
            start = 0;
            stop = k-1;
        } else {
            start = k;
            stop = nums.size()-1;
        }
        while(stop-start>=0) {
            k = start+(stop-start+1)/2;
            if(nums[k]>target) {
                stop = k-1;
            } else if(nums[k]<target) {
                start = k+1;
            } else {
                return k;
            }
        }
        return -1;
    }
};
