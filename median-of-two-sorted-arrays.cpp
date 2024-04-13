#include <bits/stdc++.h>
class Solution {
public:
    double findMedianSortedArraysRec(vector<int>& nums1, vector<int>& nums2, int start1, int start2, int end1, int end2) {

        const int len = nums1.size()+nums2.size();
        const bool even = len%2==0;
        const int target = len/2; // Upper if two targets

        if (len == 0) {
            return 0.;
        }
        
        // cout <<"Arr1 " << start1 << " " << end1 << endl;
        // cout <<"Arr2 " << start2 << " " << end2 << endl;
        if (!even) {
            if (start1 > end1) {
                return nums2[target-start1];
            } else if (start2 > end2) {
                return nums1[target-start2];
            }
        } else if (even) {
            if (start1 > end1) {
                return (nums2[target-start1]+nums2[target-start1-1])/2.;
            } else if (start2 > end2) {
                return (nums1[target-start2] + nums1[target-start2-1])/2.;
            } else if (start1 == end1 && start2 == end2) {
                return (nums1[start1] + nums2[start2])/2.;
            }
        }


        // Middle elements (or upper middle elements in even size arrs)
        int m1 = start1+(end1-start1+1)/2;
        int m2 = start2+(end2-start2+1)/2;
        int smallerElms = m1+m2; // Highest index of smaller part elements
        if (even && target == smallerElms+1) { // The problem of one target in lower half and one target in upper half
            if(end1>m1)
                m1++;
            else if(end2>m2)
                m2++;
            else if(start1<m1)
                m1--;
            else if(start2<m2)
                m2--;
            smallerElms = m1+m2;
        }
        

        if(nums1[m1] <= nums2[m2]) {
            if(target <= smallerElms) {
                return findMedianSortedArraysRec(nums1, nums2, start1, start2, end1, m2-1);
            } else {
                return findMedianSortedArraysRec(nums1, nums2, m1+1, start2, end1, end2);
            }
        } else {
            if(target<=smallerElms) {
                return findMedianSortedArraysRec(nums1, nums2, start1, start2, m1-1, end2);
            } else {
                return findMedianSortedArraysRec(nums1, nums2, start1, m2+1, end1, end2);
            }
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return findMedianSortedArraysRec(nums1, nums2, 0, 0, nums1.size()-1, nums2.size()-1);
    }
};
