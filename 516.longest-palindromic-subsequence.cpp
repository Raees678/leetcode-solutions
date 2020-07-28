/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 *
 * https://leetcode.com/problems/longest-palindromic-subsequence/description/
 *
 * algorithms
 * Medium (48.41%)
 * Total Accepted:    72.9K
 * Total Submissions: 150.5K
 * Testcase Example:  '"bbbab"'
 *
 *
 * Given a string s, find the longest palindromic subsequence's length in s.
 * You may assume that the maximum length of s is 1000.
 *
 *
 * Example 1:
 * Input:
 *
 * "bbbab"
 *
 * Output:
 *
 * 4
 *
 * One possible longest palindromic subsequence is "bbbb".
 *
 *
 * Example 2:
 * Input:
 *
 * "cbbd"
 *
 * Output:
 *
 * 2
 *
 * One possible longest palindromic subsequence is "bb".
 *
 */
class Solution {
 public:
  size_t longestLength(
      const string& s,
      std::vector<std::vector<size_t>>& longestSubsequenceLength, size_t i,
      size_t j) {
    if (i > j || i < 0 || j < 0 || i >= s.size() || j >= s.size()) {
      return 0;
    }
    if (longestSubsequenceLength[i][j] == 0) {
      if (i == j) {
        longestSubsequenceLength[i][j] = 1;
      } else if (s[i] == s[j]) {
        longestSubsequenceLength[i][j] =
            2 + longestLength(s, longestSubsequenceLength, i + 1, j - 1);
      } else {
        longestSubsequenceLength[i][j] =
            std::max(longestLength(s, longestSubsequenceLength, i + 1, j),
                     longestLength(s, longestSubsequenceLength, i, j - 1));
      }
    }
    return longestSubsequenceLength[i][j];
  }

  int longestPalindromeSubseq(string s) {
    std::vector<std::vector<size_t>> longestSubsequenceLength(
        s.size(), std::vector<size_t>(s.size(), 0));
    for (int i = s.size() - 1; i >= 0; --i) {
      for (size_t j = i; j < s.size(); ++j) {
        this->longestLength(s, longestSubsequenceLength, i, j);
      }
    }
    size_t longestLength = longestSubsequenceLength[0][s.size() - 1];
    return longestLength;
  }
};
