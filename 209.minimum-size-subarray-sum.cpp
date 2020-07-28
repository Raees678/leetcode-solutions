/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 *
 * https://leetcode.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (33.45%)
 * Likes:    1472
 * Dislikes: 83
 * Total Accepted:    206.8K
 * Total Submissions: 575.1K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * Given an array of n positive integers and a positive integer s, find the
 * minimal length of a contiguous subarray of which the sum ≥ s. If there isn't
 * one, return 0 instead.
 *
 * Example: 
 *
 *
 * Input: s = 7, nums = [2,3,1,2,4,3]
 * Output: 2
 * Explanation: the subarray [4,3] has the minimal length under the problem
 * constraint.
 *
 * Follow up:
 *
 * If you have figured out the O(n) solution, try coding another solution of
 * which the time complexity is O(n log n). 
 *
 */

// @lc code=start
class Solution {
 public:
  int minSubArrayLen(int s, vector<int>& nums) {
    if (!nums.size()) {
      return 0;
    }

    int minimum_subarray_size = INT_MAX;
    int start_index = 0;
    int end_index = 0;
    int current_subarray_sum = nums[0];

    while (start_index < nums.size() && end_index < nums.size()) {
      if (current_subarray_sum < s) {
        ++end_index;
        if (end_index < nums.size()) {
          current_subarray_sum += nums[end_index];
        }
      } else {
        int current_subarray_size = end_index - start_index + 1;
        minimum_subarray_size =
            std::min(current_subarray_size, minimum_subarray_size);
        current_subarray_sum -= nums[start_index];
        ++start_index;
        if (start_index > end_index) {
          end_index = start_index;
        }
      }
    }

    if (minimum_subarray_size == INT_MAX) {
      return 0;
    } else {
      return minimum_subarray_size;
    }
  }
};
// @lc code=end
