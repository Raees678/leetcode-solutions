/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (37.56%)
 * Likes:    1392
 * Dislikes: 48
 * Total Accepted:    291.6K
 * Total Submissions: 675K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 *
 * Example:
 *
 *
 * Input: [1,1,2]
 * Output:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 *
 *
 */

// @lc code=start
class Solution {
 public:
  void permuteUniqueHelper(vector<int>& nums, vector<bool>& used,
                           vector<int>& buffer, int buffer_index,
                           vector<vector<int>>& return_vector) {
    if (buffer_index == buffer.size()) {
      return_vector.push_back(buffer);
      return;
    }

    for (int i = 0; i < nums.size(); ++i) {
      // NOW we are picking a number to fill our buffer
      // Make sure that the number being picked hasnt been used to partially
      // fill the buffer before this
      if (!used[i]) {
        used[i] = true;
        buffer[buffer_index] = nums[i];
        permuteUniqueHelper(nums, used, buffer, buffer_index + 1,
                            return_vector);
        used[i] = false;
      }
      // we would also like to skip some future numbers:
      // skip all numbers that are the same as the current element UNLESS you
      // encounter a
      while (!used[i] && i + 1 < nums.size() && nums[i] == nums[i + 1]) {
        ++i;
      }
    }
    return;
  }

  vector<vector<int>> permuteUnique(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    vector<vector<int>> return_vector;
    vector<int> buffer(nums.size(), 0);
    vector<bool> used(nums.size(), false);
    permuteUniqueHelper(nums, used, buffer, 0, return_vector);
    return return_vector;
  }
};
// @lc code=end
