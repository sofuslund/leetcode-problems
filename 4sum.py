import time
class Solution:
    def fourSum(self, nums, target):
        ans = set()
        nums.sort() # Is n log n time complexity
        # Next part is O(n^3) time complexity (but that is worst case, it is actually on average much faster)
        counter = 0
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                # Two-pointers
                l = j+1
                r = len(nums)-1
                while l < r:
                    counter += 1
                    sum = nums[i]+nums[j]+nums[l]+nums[r]
                    if sum == target:
                        # We found four numbers that adds up to the target
                        ans.add((nums[i],nums[j],nums[l],nums[r]))
                        # But we continue finding all pairs
                        l += 1
                        r -= 1
                    elif sum < target:
                        l += 1
                    elif sum > target:
                        r -= 1
        print(counter)
        return ans                

solution = Solution()
l = [2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2]
print(solution.fourSum(l, 8))
