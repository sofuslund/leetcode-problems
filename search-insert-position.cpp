class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int stop = nums.size()-1;
        int mid;
        while(stop-start>=0) {
            mid = start + (stop-start+1)/2;
            cout << start << " " << mid << " " << stop << endl;
            if(nums[mid]<target) {
                start = mid+1;
            } else if(nums[mid]>target) {
                stop = mid-1;
            } else {
                return mid;
            }
        }
        if(nums[mid]>target)
            return mid;
        else
            return ++mid;
    }
};
