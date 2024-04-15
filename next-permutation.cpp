#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i;
        for(i = nums.size()-1; i>=1 && nums[i] <= nums[i-1]; i--) {}
        // I is now the first number bigger than its previous element (sorted)
        
        if(i!=0) {
            int next = nums.size()-1;
            // Set next to smallest number bigger than i-1 
            while(next >= i && nums[next] <= nums[i-1]) {
                next--;
            }
            iter_swap(nums.begin()+i-1, nums.begin() + next);
        }
        // We know from the while statement earlier than i and above is sorted in reverse, now we sort them
        reverse(nums.begin()+i, nums.end());
    }
};
