class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        sum_ = nums[0]
        max_ = sum_
        a = 0
        for b in range(1, len(nums)):
            if sum_ < 0:
                a = b
                sum_ = 0
            sum_ += nums[b]
            if sum_ > max_:
                max_ = sum_
        return max_
