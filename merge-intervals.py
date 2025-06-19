class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        lst = sorted(intervals, key=lambda x: x[0])
        print(lst)

        ret = []
        curr_itv = lst[0]
        for i in range(1, len(lst)):
            if lst[i][0] <= curr_itv[1]:
                curr_itv[1] = max(lst[i][1], curr_itv[1])
            else:
                ret.append(curr_itv)
                curr_itv = lst[i]
        ret.append(curr_itv)
        return ret