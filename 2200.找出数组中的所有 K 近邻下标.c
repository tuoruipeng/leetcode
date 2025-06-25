/*
 * @lc app=leetcode.cn id=2200 lang=c
 * @lcpr version=30201
 *
 * [2200] 找出数组中的所有 K 近邻下标
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int* findKDistantIndices(int* nums, int numsSize, int key, int k, int* returnSize) {
    int r, l;
    int *ans = (int *)malloc(sizeof(int) * numsSize);

    *returnSize = 0;
    memset(ans, 0, sizeof(int) * numsSize);

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == key) {
            r = MIN(i + k, numsSize - 1);
            l = MAX(i - k, 0);
            // printf("i: %d, l: %d, r: %d\n", i, l, r);
            for (int j = l; j <= r; j++) {
                if (*returnSize > 0 && ans[*returnSize - 1] >= j) {
                    continue; // Skip if this index is already added
                }
                ans[(*returnSize)++] = j; // Mark this index as valid
            }
            // i = r; // Skip to the end of the current range
        }
    }
    // printf("returnSize: %d\n", *returnSize);
    // for (int i = 0; i < *returnSize; i++) {
    //     printf("%d ", ans[i]);
    // }

    return ans;
}
// @lc code=end



/*
// @lcpr case=start
// [3,4,9,1,3,9,5]\n9\n1\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,2,2]\n2\n2\n
// @lcpr case=end

// @lcpr case=start
// [734,228,636,204,552,732,686,461,973,874,90,537,939,986,855,387,344,939,552,389,116,93,545,805,572,306,157,899,276,479,337,219,936,416,457,612,795,221,51,363,667,112,686,21,416,264,942,2,127,47,151,277,603,842,586,630,508,147,866,434,973,216,656,413,504,360,990,228,22,368,660,945,99,685,28,725,673,545,918,733,158,254,207,742,705,432,771,578,549,228,766,998,782,757,561,444,426,625,706,946]\n939\n34\n
// @lcpr case=end

 */

