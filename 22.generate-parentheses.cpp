/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (51.03%)
 * Likes:    3644
 * Dislikes: 212
 * Total Accepted:    428.4K
 * Total Submissions: 734.3K
 * Testcase Example:  '3'
 *
 *
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 *
 *
 *
 * For example, given n = 3, a solution set is:
 *
 *
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 *
 */

// @lc code=start
class Solution {
 public:
  void generateParenthesisHelper(int n, std::string buffer, int buffer_index,
                                 int opened_brackets, int unclosed_brackets,
                                 std::vector<string>& return_vector) {
    if (buffer_index == buffer.size()) {
      return_vector.push_back(buffer);
      return;
    }

    if (opened_brackets < n) {
      buffer[buffer_index] = '(';
      generateParenthesisHelper(n, buffer, buffer_index + 1,
                                opened_brackets + 1, unclosed_brackets + 1,
                                return_vector);
    }

    if (unclosed_brackets > 0) {
      buffer[buffer_index] = ')';
      generateParenthesisHelper(n, buffer, buffer_index + 1, opened_brackets,
                                unclosed_brackets - 1, return_vector);
    }
    return;
  }
  vector<string> generateParenthesis(int n) {
    std::vector<string> return_vector;
    if (!n) {
      return return_vector;
    }
    std::string buffer(n * 2, '\0');
    generateParenthesisHelper(n, buffer, 0, 0, 0, return_vector);
    return return_vector;
  }
};
// @lc code=end
