/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (41.65%)
 * Likes:    5459
 * Dislikes: 227
 * Total Accepted:    681.9K
 * Total Submissions: 1.5M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 *
 * Example:
 *
 *
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 *
 *
 * Follow up:
 *
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 *
 */

// @lc code=start
class Solution {
 public:
  // O(n) solution
  int maxSubArray(vector<int>& nums) {
    int prev_max_sum = nums[0];
    int max_sum = prev_max_sum;
    for (int i = 1; i < nums.size(); ++i) {
      int current_max_sum = std::max(prev_max_sum + nums[i], nums[i]);
      if (current_max_sum > max_sum) {
        max_sum = current_max_sum;
      }
      prev_max_sum = current_max_sum;
    }
    return max_sum;
  }
};
// @lc code=end
