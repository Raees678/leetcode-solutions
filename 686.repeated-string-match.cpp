/*
 * @lc app=leetcode id=686 lang=cpp
 *
 * [686] Repeated String Match
 *
 * https://leetcode.com/problems/repeated-string-match/description/
 *
 * algorithms
 * Easy (31.71%)
 * Likes:    602
 * Dislikes: 599
 * Total Accepted:    78.8K
 * Total Submissions: 247K
 * Testcase Example:  '"abcd"\n"cdabcdab"'
 *
 * Given two strings A and B, find the minimum number of times A has to be
 * repeated such that B is a substring of it. If no such solution, return -1.
 *
 * For example, with A = "abcd" and B = "cdabcdab".
 *
 * Return 3, because by repeating A three times (“abcdabcdabcd”), B is a
 * substring of it; and B is not a substring of A repeated two times
 * ("abcdabcd").
 *
 * Note:
 * The length of A and B will be between 1 and 10000.
 *
 */

// @lc code=start
class Solution {
 public:
  int repeatedStringMatch(string A, string B) {
    // kmp with wrap around
  }
};
// @lc code=end
