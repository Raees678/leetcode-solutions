/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 *
 * https://leetcode.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (33.73%)
 * Likes:    1416
 * Dislikes: 3247
 * Total Accepted:    447.1K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
 * one sorted array.
 *
 * Note:
 *
 *
 * The number of elements initialized in nums1 and nums2 are m and n
 * respectively.
 * You may assume that nums1 has enough space (size that is greater or equal to
 * m + n) to hold additional elements from nums2.
 *
 *
 * Example:
 *
 *
 * Input:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 *
 * Output: [1,2,2,3,5,6]
 *
 */

// @lc code=start
class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int insert_index = nums1.size() - 1;
    --m;
    --n;
    while (m >= 0 && n >= 0) {
      if (nums1[m] >= nums2[n]) {
        nums1[insert_index] = nums1[m];
        --m;
      } else {
        nums1[insert_index] = nums2[n];
        --n;
      }
      --insert_index;
    }

    while (n >= 0) {
      nums1[insert_index] = nums2[n];
      --n;
      --insert_index;
    }
  }
};
// @lc code=end
