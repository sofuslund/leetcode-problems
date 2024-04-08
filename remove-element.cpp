class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                cout << nums[i] << endl;
                nums.erase(nums.begin() + i);
                i--;
                k--;
            }
        }
        return k;
    }
};
