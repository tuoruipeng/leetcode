/*
 * @lc app=leetcode.cn id=2040 lang=c
 * @lcpr version=30201
 *
 * [2040] 两个有序数组的第 K 小乘积
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// 比较函数用于二分查找
int compare(const void *a, const void *b)
{
    long long arg1 = *(const long long*)a;
    long long arg2 = *(const long long*)b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

// 计算nums1[i] * nums2[j] <= mid的数量
long long countLessOrEqual(int* nums1, int nums1Size, int* nums2, int nums2Size, long long mid)
{
    long long count = 0;
    for (int i = 0; i < nums1Size; i++) {
        long long num1 = nums1[i];
        if (num1 == 0) {
            if (mid >= 0) {
                count += nums2Size;
            }
            continue;
        }
        
        long long left = 0, right = nums2Size - 1;
        long long temp = 0;
        if (num1 > 0) {
            // 找最大的nums2[j]使得num1 * nums2[j] <= mid
            while (left <= right) {
                long long m = left + (right - left) / 2;
                if (num1 * nums2[m] <= mid) {
                    temp = m + 1;
                    left = m + 1;
                } else {
                    right = m - 1;
                }
            }
        } else {
            // 找最小的nums2[j]使得num1 * nums2[j] <= mid
            while (left <= right) {
                long long m = left + (right - left) / 2;
                if (num1 * nums2[m] <= mid) {
                    temp = nums2Size - m;
                    right = m - 1;
                } else {
                    left = m + 1;
                }
            }
        }
        count += temp;
    }
    return count;
}

long long kthSmallestProduct(int* nums1, int nums1Size, int* nums2, int nums2Size, long long k) {
    // 确定二分查找的左右边界
    long long left = -1e11, right = 1e11;
    long long result = 0;
    
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long cnt = countLessOrEqual(nums1, nums1Size, nums2, nums2Size, mid);
        if (cnt >= k) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}
// @lc code=end



/*
// @lcpr case=start
// [2,5]\n[3,4]\n2\n
// @lcpr case=end

// @lcpr case=start
// [-4,-2,0,3]\n[2,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [-2,-1,0,1,2]\n[-3,-1,2,4,5]\n3\n
// @lcpr case=end

 */

