class Solution:
    def canJump(self, nums: List[int]) -> bool:
        max_pos = 0
        for i in range(len(nums)):
            if max_pos < i:
                break
            if i + nums[i] > max_pos:
                max_pos = i + nums[i]
        return (max_pos >= len(nums)-1)