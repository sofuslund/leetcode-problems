class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        if not nums:
            return []
        d = {}
        for num in nums:
            if num in d:
                d[num] += 1
            else:
                d[num] = 1
        perms = []

        def helper(dct, perm):
            print(perms)
            if not dct and perm:
                perms.append(perm)
            for k, v in dct.items():
                tmp = dct.copy()
                tmp[k] -= 1
                if tmp[k] == 0:
                    del tmp[k]
                helper(tmp, perm + [k])
          
        helper(d, [])
        return perms
