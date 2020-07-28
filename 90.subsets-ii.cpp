/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (40.21%)
 * Likes:    1190
 * Dislikes: 56
 * Total Accepted:    236.4K
 * Total Submissions: 531.5K
 * Testcase Example:  '[1,2,2]'
 *
 * Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets (the power set).
 *
 * Note: The solution set must not contain duplicate subsets.
 *
 * Example:
 *
 *
 * Input: [1,2,2]
 * Output:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 *
 *
 */

// @lc code=start
class Solution {
 public:
  void subsetsWithDupHelper(vector<int>& nums, vector<int>& buffer,
                            int start_index, vector<int>::iterator buffer_index,
                            vector<vector<int>>& return_vector) {
    return_vector.push_back(vector<int>(buffer.begin(), buffer_index));
    if (buffer_index == buffer.end()) {
      return;
    }
    for (int i = start_index; i < nums.size(); ++i) {
      if (i == start_index || nums[i] != nums[i - 1]) {
        *buffer_index = nums[i];
        subsetsWithDupHelper(nums, buffer, i + 1, buffer_index + 1,
                             return_vector);
      }
    }
    return;
  }

  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    vector<vector<int>> return_vector;
    vector<int> buffer(nums.size(), 0);
    subsetsWithDupHelper(nums, buffer, 0, buffer.begin(), return_vector);
    return return_vector;
  }
};
// @lc code=end
