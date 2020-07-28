/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (25.24%)
 * Likes:    6865
 * Dislikes: 409
 * Total Accepted:    1.2M
 * Total Submissions: 4.1M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 *
 *
 * Example 1:
 *
 *
 * Input: "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 *
 *
 *
 * Example 2:
 *
 *
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 *
 *
 *
 * Example 3:
 *
 *
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 *
 *
 *
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    if (s.size() == 0 || s.size() == 1) {
      return s.size();
    }

    std::vector<int> letters(256);
    int current_length = 1;
    int longest_lengh = 1;
    int start_index = 0;
    letters[s[start_index]] = 1;
    int end_index = 1;

    while (start_index < s.size() && end_index < s.size()) {
      if (!letters[s[end_index]]) {
        letters[s[end_index]] = end_index;
        ++current_length;
        longest_lengh = std::max(longest_lengh, current_length);
        ++end_index;
      } else {
        char duplicate_char = s[end_index];
        letters[s[start_index]] = 0;
        --current_length;
        ++start_index;
      }
    }

    return longest_lengh;
  }
};
// @lc code=end
