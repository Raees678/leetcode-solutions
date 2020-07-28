/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (27.76%)
 * Likes:    2703
 * Dislikes: 120
 * Total Accepted:    257.9K
 * Total Submissions: 849.6K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * Given an integer array nums, find the contiguous subarray within an array
 * (containing at least one number) which has the largest product.
 *
 * Example 1:
 *
 *
 * Input: [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 *
 *
 * Example 2:
 *
 *
 * Input: [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 *
 */

// @lc code=start
class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int max_product = nums[0];
    int max_ending_previous = nums[0];
    int min_ending_previous = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
      int max_ending_here = std::max(max_ending_previous * nums[i],
                                     min_ending_previous * nums[i]);
      max_ending_here = std::max(max_ending_here, nums[i]);
      int min_ending_here = std::min(max_ending_previous * nums[i],
                                     min_ending_previous * nums[i]);
      min_ending_here = std::min(min_ending_here, nums[i]);
      max_product = std::max(max_ending_here, max_product);
      max_ending_previous = max_ending_here;
      min_ending_previous = min_ending_here;
    }

    return max_product;
  }
};
// @lc code=end
