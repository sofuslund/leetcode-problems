class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        closest_init = False
        closest = 0
        for i in range(len(nums)):
            j = i+1
            k = len(nums)-1
            while j < k:
                val = nums[i] + nums[j] + nums[k]
                if val < target:
                    j += 1
                elif val > target:
                    k -= 1
                elif val == target:
                    return target
                
                if not closest_init:
                    closest = val
                    closest_init = True
                elif abs(target-closest)>abs(target-val):
                    closest = val
                
        return closest
