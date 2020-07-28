/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 *
 * https://leetcode.com/problems/repeated-substring-pattern/description/
 *
 * algorithms
 * Easy (38.78%)
 * Likes:    957
 * Dislikes: 108
 * Total Accepted:    93K
 * Total Submissions: 228.2K
 * Testcase Example:  '"abab"'
 *
 * Given a non-empty string check if it can be constructed by taking a
 * substring of it and appending multiple copies of the substring together. You
 * may assume the given string consists of lowercase English letters only and
 * its length will not exceed 10000.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: "abab"
 * Output: True
 * Explanation: It's the substring "ab" twice.
 *
 *
 * Example 2:
 *
 *
 * Input: "aba"
 * Output: False
 *
 *
 * Example 3:
 *
 *
 * Input: "abcabcabcabc"
 * Output: True
 * Explanation: It's the substring "abc" four times. (And the substring
 * "abcabc" twice.)
 *
 *
 */

// @lc code=start
class Solution {
 public:
  bool repeatedSubstringPattern(string s) {
    // compute the largest proper border of s
    // using knuth morris pratt algorithm
    // initialize a vector that holds the largest border for the substring
    // ending at each index
    std::vector<int> largest_border_ending_here(s.size());
    int border = 0;

    for (int i = 1; i < largest_border_ending_here.size(); ++i) {
      while (border > 0 && s[i] != s[border]) {
        border = largest_border_ending_here[border - 1];
      }

      if (s[i] == s[border]) {
        ++border;
      } else {
        border = 0;
      }
      largest_border_ending_here[i] = border;
    }

    int largest_border_size = largest_border_ending_here[s.size() - 1];
    // get the smallest period of s
    int smallest_period_size = s.size() - largest_border_size;
    if (!(s.size() % smallest_period_size) && smallest_period_size < s.size()) {
      return true;
    }
    return false;
  }
};
// @lc code=end
