/*
 * @lc app=leetcode id=713 lang=cpp
 *
 * [713] Subarray Product Less Than K
 *
 * https://leetcode.com/problems/subarray-product-less-than-k/description/
 *
 * algorithms
 * Medium (34.38%)
 * Likes:    839
 * Dislikes: 44
 * Total Accepted:    41.5K
 * Total Submissions: 109K
 * Testcase Example:  '[10,5,2,6]\n100'
 *
 * Your are given an array of positive integers nums.
 * Count and print the number of (contiguous) subarrays where the product of
 * all the elements in the subarray is less than k.
 *
 * Example 1:
 *
 * Input: nums = [10, 5, 2, 6], k = 100
 * Output: 8
 * Explanation: The 8 subarrays that have product less than 100 are: [10], [5],
 * [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
 * Note that [10, 5, 2] is not included as the product of 100 is not strictly
 * less than k.
 *
 *
 *
 * Note:
 * 0 < nums.length .
 * 0 < nums[i] < 1000.
 * 0 .
 *
 */

// @lc code=start
class Solution {
 public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if (k <= 1) {
      return 0;
    }

    int start_index = 0;
    int end_index = 0;
    int product_so_far = nums[0];
    int number_of_products = 0;

    while (start_index < nums.size() && end_index < nums.size()) {
      if (product_so_far < k) {
        number_of_products += end_index - start_index + 1;
        ++end_index;
        if (end_index < nums.size()) {
          product_so_far *= nums[end_index];
        }
      } else {
        product_so_far /= nums[start_index];
        ++start_index;
        if (start_index > end_index) {
          end_index = start_index;
          if (end_index < nums.size()) {
            product_so_far = nums[start_index];
          }
        }
      }
    }

    return number_of_products;
  }
};
// @lc code=end
