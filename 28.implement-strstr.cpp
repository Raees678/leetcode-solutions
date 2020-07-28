/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (30.27%)
 * Likes:    1132
 * Dislikes: 1569
 * Total Accepted:    527.7K
 * Total Submissions: 1.6M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 *
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 *
 * Example 1:
 *
 *
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 *
 *
 * Clarification:
 *
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 *
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 *
 */

// @lc code=start
class Solution {
 public:
  void computeBorder(const string& haystack, const string& needle,
                     std::vector<int>& border_table) {
    // border_table[0] = 0;
    // border is the border of the substring till the previous element
    border_table[0] = 0;
    int border = border_table[0];
    for (int i = 1; i < needle.size(); ++i) {
      std::cout << i << std::endl;
      while (border > 0 && needle[i] != needle[border]) {
        border = border_table[border - 1];
      }
      if (needle[i] == needle[border]) {
        border = border + 1;
      } else {
        border = 0;
      }
      border_table[i] = border;
    }
  }

  int strStr(string haystack, string needle) {
    if (!needle.size()) {
      return 0;
    }
    std::vector<int> border_table(needle.size());
    computeBorder(haystack, needle, border_table);
    int haystack_index = 0;
    int needle_index = 0;

    while (haystack_index < haystack.size()) {
      if (haystack[haystack_index] == needle[needle_index]) {
        ++haystack_index;
        ++needle_index;
      }

      if (needle_index == needle.size()) {
        return haystack_index - needle_index;
      } else if (haystack_index < haystack.size() &&
                 haystack[haystack_index] != needle[needle_index]) {
        if (needle_index == 0) {
          ++haystack_index;
        } else {
          needle_index = border_table[needle_index - 1];
        }
      }
    }

    return -1;
  }
};
// @lc code=end
