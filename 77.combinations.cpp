/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (44.16%)
 * Likes:    1041
 * Dislikes: 58
 * Total Accepted:    241.6K
 * Total Submissions: 474.6K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 *
 * Example:
 *
 *
 * Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 *
 *
 */

// @lc code=start
class Solution {
 public:
  void combineHelper(int n, vector<int>& buffer, int n_index, int buffer_index,
                     vector<vector<int>>& return_vector) {
    if (buffer_index == buffer.size()) {
      return_vector.push_back(buffer);
      return;
    }

    for (int i = n_index; i <= n; ++i) {
      buffer[buffer_index] = i;
      combineHelper(n, buffer, i + 1, buffer_index + 1, return_vector);
    }
  }

  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> return_vector;
    vector<int> buffer(k, 0);
    combineHelper(n, buffer, 1, 0, return_vector);
    return return_vector;
  }
};
// @lc code=end
