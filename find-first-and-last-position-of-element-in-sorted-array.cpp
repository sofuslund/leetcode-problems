class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0, stop = nums.size()-1, mid = 0;
        int smaller = -1, bigger = nums.size();

        while(stop-start+1>0) {
            mid = start + (stop-start+1)/2;
            if(target>nums[mid]) {
                smaller = mid;
                start = mid+1;
            } else if(target<nums[mid]) {
                bigger = mid;
                stop = mid-1;
            } else {
                int prev_mid = mid;

                // Find closest smaller element to target
                start = smaller+1;
                stop = mid-1;
                while(stop-start+1>0) {
                    mid = start + (stop-start+1)/2;
                    if(nums[mid] == target) {
                        stop = mid-1;
                    } else if (nums[mid] < target) {
                        smaller = mid;
                        start = mid+1;
                    }
                }

                mid = prev_mid;
                // Find closest bigger element to target
                start = mid+1;
                stop = bigger-1;
                while(stop-start+1>0) {
                    mid = start + (stop-start+1)/2;
                    if(nums[mid] == target) {
                        start = mid+1;
                    } else if (nums[mid] > target) {
                        bigger = mid;
                        stop = mid-1;
                    }
                }
                return {smaller+1, bigger-1};
            }
        }
        return {-1, -1};
    }
};
