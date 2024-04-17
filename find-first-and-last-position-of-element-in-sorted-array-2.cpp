#include <bits/stdc++.h>
class Solution {
    int start = 0;
    int mid = 0;
    int stop = 0;
    int less = 0;
    int greater = 0;
    int bin_search(vector<int> arr, int target) {
        while(stop-start>=0) {
            mid = start + (stop-start+1)/2;
            if(arr[mid] > target) {
                greater = mid;
                stop = mid-1;
            } else if(arr[mid] < target) {
                less = mid;
                start = mid+1;
            } else {
                return mid;
            }
        }
        return -1;
    }
    int bin_search_less(vector<int> arr, int target) {
        while(stop-start>=0) {
            mid = start + (stop-start+1)/2;
            if(arr[mid] == target) {
                stop = mid-1;
            } else if(arr[mid] < target) {
                less = mid;
                start = mid+1;
            }
        }
        return less;
    }
    int bin_search_greater(vector<int> arr, int target) {
        while(stop-start >= 0) {
            mid = start + (stop-start+1)/2;
            if(arr[mid] == target) {
                start = mid+1;
            } else if(arr[mid] > target) {
                greater = mid;
                stop = mid-1;
            }
        }
        return greater;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        start = 0;
        stop = nums.size()-1;
        less = start;
        greater = stop;
        vector<int> ans = {-1, -1};
        if(bin_search(nums, target) == -1)
            return ans;

        int prev_mid = mid;
        int prev_stop = stop;
        stop = prev_mid-1;
        ans[0] = bin_search_less(nums, target);
        if(nums[ans[0]] != target)
            ans[0]++;
        stop = prev_stop;
        start = prev_mid+1;
        ans[1] = bin_search_greater(nums, target);
        if(nums[ans[1]] != target)
            ans[1]--;

        return ans;
    }
};
