class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        result = set()
        nums.sort()

        for i in range(len(nums)):
            j = i+1
            k = len(nums)-1
            while k>j:
                val = nums[i] + nums[j] + nums[k]
                if val == 0:
                    result.add((nums[i], nums[j], nums[k]))
                    j += 1
                elif val > 0:
                    k -= 1
                elif val < 0:
                    j += 1

        return result
