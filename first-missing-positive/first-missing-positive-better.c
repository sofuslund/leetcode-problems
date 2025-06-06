#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int firstMissingPositive(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] <= 0 || nums[i] > numsSize) {
            nums[i] = 0;
        } else if (nums[i] != i + 1) {
            if (nums[nums[i] - 1] == nums[i]) {
                nums[i] = 0;
            } else {
                int tmp = nums[nums[i] - 1];
                nums[nums[i] - 1] = nums[i];
                nums[i] = tmp;
                i--;
            }
        }
    }
    // for (int i = 0; i < numsSize; i++) {
    //     printf("%d ", nums[i]);
    // }
    int i = 0;
    while (i < numsSize && nums[i] != 0) {
        i++;
    }
    return i+1;
}
int test(int* nums, int numsSize, int expected) {
    int result = firstMissingPositive(nums, numsSize);
    if (result == expected) {
        printf("Test passed: Expected %d, got %d\n", expected, result);
    } else {
        printf("Test failed: Expected %d, got %d\n", expected, result);
    }
    return result;
}
int main(int argc, char* argv[]) {
    int nums1[] = {1,2,0};
    int nums2[] = {3,4,-1,1};
    int nums3[] = {7,8,9,11,12};
    int nums4[] = {1, 2, 3, 4, 5};
    int nums5[] = {0, -1, -2, -3};
    int nums6[] = {1, 2, 3, 5, 6};
    int nums7[] = {3, 1, 2, 8, 7, 7, 7, 9, -9, -4, -3, -2, 6, 5, 4, 10, 11, 12, 15, 13, 17, 18, 33, 20, 25, 24, -4, -2, -10, -40, -33, -4, -4, 33, 1, 2};
    int nums8[] = {1,1};
    test(nums1, sizeof(nums1)/sizeof(nums1[0]), 3);
    test(nums2, sizeof(nums2)/sizeof(nums2[0]), 2);
    test(nums3, sizeof(nums3)/sizeof(nums3[0]), 1);
    test(nums4, sizeof(nums4)/sizeof(nums4[0]), 6);
    test(nums5, sizeof(nums5)/sizeof(nums5[0]), 1);
    test(nums6, sizeof(nums6)/sizeof(nums6[0]), 4);
    test(nums7, sizeof(nums7)/sizeof(nums7[0]), 14);
    test(nums8, sizeof(nums8)/sizeof(nums8[0]), 2);
    return 0;
}