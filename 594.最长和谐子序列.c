/*
 * @lc app=leetcode.cn id=594 lang=c
 * @lcpr version=30201
 *
 * [594] 最长和谐子序列
 */

// @lc code=start
#if 0
/* 最小子串答案 */
int findLHS(int* nums, int numsSize) {
    int max = 0;

    for (int i = 0; i < numsSize; i++) {
        int count = 1; // Count the current number itself
        int sum = 0;
        int j = i + 1; // Start checking from the next number
        for (; j < numsSize; j++) {
            if (nums[j] == nums[i]) {
                count++;
            } else if (nums[j] == nums[i] + 1 || nums[j] == nums[i] - 1) {
                sum++;
            } else {
                break; // Stop counting when a different number is encountered
            }
        }

        if (sum > 0) {
            sum += count; // Include the count of the current number
            max = sum > max ? sum : max;
            i = j - 1; // Skip to the next different number
        }
    }
    return max;
}
#endif
#if 0
/* case 185: Time Limit Exceeded */
int findLHS(int* nums, int numsSize) {
    int max = 0;

    for (int i = 0; i < numsSize; i++) {
        int count = 1; // Count the current number itself
        int sum1 = 0;
        int sum2 = 0;
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[j] == nums[i]) {
                count++;
            } else if (nums[j] == nums[i] + 1) {
                sum1++;
            } else if (nums[j] == nums[i] - 1) {
                sum2++;
            }
        }

        if (sum1 > 0) {
            sum1 += count; // Include the count of the current number
            max = sum1 > max ? sum1: max;
        }
        if (sum2 > 0) {
            sum2 += count; // Include the count of the current number
            max = sum2 > max ? sum2: max;
        }
    }
    return max;
}
#endif

int mycompare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int findLHS(int* nums, int numsSize) {
    int max = 0;
    int last_count = 0;

    qsort(nums, numsSize, sizeof(int), mycompare);

    for (int i = 0; i < numsSize; i++) {
        int j = i + 1; // Start checking from the next number
        int count = 0; // Count the current number itself

        for (; j < numsSize; j++) {
            if (nums[j] != nums[i]) {
                break; // Stop counting when a different number is encountered
            }
        }

        count = j - i; // Count of the current number
        if ((last_count != 0) && (nums[i] == nums[i - 1] + 1)) {
            // Check if the current number is adjacent to the previous number
            max = (last_count + count > max) ? (last_count + count) : max;
        }
        last_count = count; // Store the count of the first number
        i = j - 1; // Skip to the next different number
    }

    return max;
}
// @lc code=end



/*
// @lcpr case=start
// [1,3,2,2,5,2,3,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,1,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,1,3,0,0,2,2,1,3,3]\n
// @lcpr case=end

 */

