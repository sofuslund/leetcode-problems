#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int printNummap(int* nummap, int print_count) {
    for (int i = 0; i < print_count; i++) {
        printf("%d: %d\n", i, (nummap[i/8] & (1 << (i % 8)) ? 1 : 0));
    }
    return 0;
}
int firstMissingPositive(int* nums, int numsSize) {
    const int nummap_size = pow(2, 31)/8;
    int* nummap = (int*)calloc(nummap_size, sizeof(int));
    if (nummap == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return -1;
    }
    // Flip bits in nummap for each positive number in nums
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < 1) {
            continue; // Skip non-positive numbers
        }
        nummap[nums[i] / 8] |= (1 << (nums[i] % 8));
    }
    printNummap(nummap, 10);
    // Find the first not set bit in nummap
    int i = 1;
    while (i < nummap_size && nummap[i / 8] & (1 << (i % 8))) {
        i++;
    }
    free(nummap);
    return i;
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
    test(nums1, sizeof(nums1)/sizeof(nums1[0]), 3);
    test(nums2, sizeof(nums2)/sizeof(nums2[0]), 2);
    test(nums3, sizeof(nums3)/sizeof(nums3[0]), 1);
    test(nums4, sizeof(nums4)/sizeof(nums4[0]), 6);
    test(nums5, sizeof(nums5)/sizeof(nums5[0]), 1);
    test(nums6, sizeof(nums6)/sizeof(nums6[0]), 4);
    test(nums7, sizeof(nums7)/sizeof(nums7[0]), 14);
    return 0;
}