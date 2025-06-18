class Solution:
    def canJump(self, nums: List[int]) -> bool:
        dp = [-1]*len(nums) # -1: not initialized, 0: no, 1: yes
        def can_(n):
            if dp[n] != -1:
                return bool(dp[n])
            achievable = False
            if n+nums[n] >= len(nums)-1:
                achievable = True
            elif nums[n] == 0:
                achievable = False
            else:
                for i in range(1, nums[n]+1):
                    if can_(n+i):
                        achievable = True
            dp[n] = int(achievable)
            return achievable
        return can_(0)