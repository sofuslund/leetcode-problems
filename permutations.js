/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function(nums) {
    if (nums.length == 1) {
        return [nums];
    }
    let perms = permute(nums.slice(1, nums.length));
    let perms_total = [];
    for (let i = 0; i < nums.length; i++) {
        for (const perm of perms) {
            perms_total.push(perm.toSpliced(i, 0, nums[0]));
        }
    }
    return perms_total;
};
