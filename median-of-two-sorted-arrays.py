class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        def findMedian(a, b, a_start, a_end, b_start, b_end):
            # The target index of a + b sorted (more specifically the sub lists a + b sorted i.e. taking account of a- and b_start and a- and b_end)
            # For an even list it is the lower index of the two targets
            k = math.ceil((len(a) + len(b))/2 - 1)
            # The pivots
            # They are the middle element of an odd list or the upper middle element of an even list
            pa = a_start + math.ceil((a_end-a_start)/2)
            pb = b_start + math.ceil((b_end-b_start)/2)

            print(a[a_start:a_end+1], b[b_start:b_end+1])

            even = (len(a) + len(b)) % 2 == 0
            # If the length of a + b is even
            if even:
                # If only two elements are left
                if a_end+b_end-a_start-b_start == 0:
                    tmp = a[a_start:a_end+1] + b[b_start:b_end+1]
                    return (tmp[0]+tmp[1])/2
                # If there are only elements in either a or b
                if a_end-a_start < 0:
                    return (b[k-a_start]+b[k+1-a_start])/2
                if b_end-b_start < 0:
                    return (a[k-b_start]+a[k+1-b_start])/2
            else: # If the length of a + b is odd there are only elements in either a or b
                if a_end-a_start < 0:
                    return b[k-a_start]
                if b_end-b_start < 0:
                    return a[k-b_start]

            # For example if a[pa] < a[pb] then elements a[<=pa] are for sure among the lower_part lowest elements
            lower_part = pa+pb+1


            # What if one k is in the lower part, and the other is in the upper part?
            # This creates a problem: we can't remove any parts because we may remove one of the k's
            # We need to make sure that that does not happen
            if k == (lower_part-1):
                if a_end>pa:
                    pa += 1
                elif a_start<pa:
                    pa -= 1
                elif b_end>pb:
                    pb += 1
                elif b_start<pb:
                    pb -= 1
                lower_part = pa+pb+1

            print(a[a_start:a_end+1], b[b_start:b_end+1], k-a_start-b_start, pa-a_start, pb-b_start, lower_part-a_start-b_start)

            # Indexes < pa are in the lower part of a + b sorted, indexes > pb are in the upper part of a + b sorted
            if a[pa] <= b[pb]:
                if even:
                    # Both k's (targets) are in the lower part therefore we remove the elements that are for sure in the upper part
                    if (k+1) <= (lower_part-1):
                        return findMedian(a, b, a_start, a_end, b_start, pb-1)
                    # Both k's are in the upper part so we remove elements that are for sure in the lower part
                    else:
                        return findMedian(a, b, pa+1, a_end, b_start, b_end)
                else:
                    # If the target index is in the lower part of a + b sorted, then discard the indexes > pb
                    if k <= (lower_part-1):
                        return findMedian(a, b, a_start, a_end, b_start, pb-1)
                    # If the target index is in the upper part of a + b sorted, then discard the indexes <= pa
                    else:
                        return findMedian(a, b, pa+1, a_end, b_start, b_end)
            # Indexes > pa are in the upper part of a + b sorted, indexes < pb are in the lower part of a + b sorted
            elif a[pa] > b[pb]:
                if even:
                    if (k+1) <= (lower_part-1):
                        return findMedian(a, b, a_start, pa-1, b_start, b_end)
                    else:
                        return findMedian(a, b, a_start, a_end, pb+1, b_end)
                else:
                    if k <= (lower_part-1):
                        return findMedian(a, b, a_start, pa-1, b_start, b_end)
                    else:
                        return findMedian(a, b, a_start, a_end, pb+1 , b_end)
                    
        
        return findMedian(nums1, nums2, 0, len(nums1)-1, 0, len(nums2)-1)
