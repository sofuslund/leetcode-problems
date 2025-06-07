class Solution:
    def jump(self, nums: List[int]) -> int:
        dp = [-1] * len(nums)
        def helper(nums, start):
            if not nums or len(nums)==start+1:
                return 0
            if start + nums[start] >= len(nums)-1:
                return 1
            best = float('inf')
            for jmp in range(nums[start], 0, -1):
                if dp[start+jmp] == -1:
                    dp[start+jmp] = 1 + helper(nums, start+jmp)
                best = min(dp[start+jmp], best)
            dp[start] = best
            return best
        return helper(nums, 0)
