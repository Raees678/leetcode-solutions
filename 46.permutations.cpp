/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (51.05%)
 * Likes:    2717
 * Dislikes: 88
 * Total Accepted:    473.1K
 * Total Submissions: 804.8K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 *
 * Example:
 *
 *
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 *
 *
 */

// @lc code=start
class Solution {
 public:
  void permuteHelper(vector<int>& nums, vector<bool>& number_used,
                     vector<int>& buffer, int buffer_index,
                     vector<vector<int>>& return_vector) {
    if (buffer_index == nums.size()) {
      return_vector.push_back(buffer);
      return;
    }

    for (int i = 0; i < nums.size(); ++i) {
      if (!number_used[i]) {
        buffer[buffer_index] = nums[i];
        number_used[i] = true;
        permuteHelper(nums, number_used, buffer, buffer_index + 1,
                      return_vector);
        number_used[i] = false;
      }
    }
  }

  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> return_vector;
    vector<int> buffer(nums.size(), 0);
    vector<bool> number_used(nums.size(), false);
    permuteHelper(nums, number_used, buffer, 0, return_vector);
    return return_vector;
  }
};
// @lc code=end
