/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (48.63%)
 * Likes:    2535
 * Dislikes: 62
 * Total Accepted:    441.5K
 * Total Submissions: 785.7K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 *
 * Note: The solution set must not contain duplicate subsets.
 *
 * Example:
 *
 *
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 *
 */

// @lc code=start
class Solution {
 public:
  void subsetsHelper(std::vector<int>& nums, int start_index,
                     std::vector<int>& buffer,
                     std::vector<int>::iterator buffer_it,
                     std::vector<std::vector<int>>& return_vector) {
    return_vector.push_back(std::vector<int>(buffer.begin(), buffer_it));
    if (buffer_it == buffer.end()) {
      return;
    }

    for (int i = start_index; i < nums.size(); ++i) {
      *buffer_it = nums[i];
      subsetsHelper(nums, i + 1, buffer, buffer_it + 1, return_vector);
    }
    return;
  }

  std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
    std::vector<std::vector<int>> return_vector;
    std::vector<int> buffer(nums.size(), 0);
    subsetsHelper(nums, 0, buffer, buffer.begin(), return_vector);
    return return_vector;
  }
};
// @lc code=end
