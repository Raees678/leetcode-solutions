/*
 * @lc app=leetcode id=159 lang=cpp
 *
 * [159] Longest Substring with At Most Two Distinct Characters
 *
 * https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/description/
 *
 * algorithms
 * Hard (44.32%)
 * Likes:    661
 * Dislikes: 14
 * Total Accepted:    84.2K
 * Total Submissions: 174.5K
 * Testcase Example:  '"eceba"'
 *
 * Given a string s , find the length of the longest substring t  that
 * contains at most 2 distinct characters.
 *
 * Example 1:
 *
 *
 * Input: "eceba"
 * Output: 3
 * Explanation: t is "ece" which its length is 3.
 *
 *
 * Example 2:
 *
 *
 * Input: "ccaabbb"
 * Output: 5
 * Explanation: t is "aabbb" which its length is 5.
 *
 */

// @lc code=start
#include <algorithm>
#include <unordered_set>
class Solution {
 public:
  int lengthOfLongestSubstringTwoDistinct(string s) {
    if (!s.size() || s.size() == 1) {
      return s.size();
    }

    std::unordered_map<char, int> distinct_characters;
    int start_index = 0;
    ++distinct_characters[s[start_index]];
    int end_index = 1;
    int current_length = 1;
    int longest_length = current_length;

    while (start_index < s.size() && end_index < s.size()) {
      if (distinct_characters.find(s[end_index]) != distinct_characters.end() ||
          distinct_characters.size() < 2) {
        ++distinct_characters[s[end_index]];
        ++end_index;
        ++current_length;
        longest_length = std::max(longest_length, current_length);
      } else {
        if (distinct_characters[s[start_index]] > 1) {
          --distinct_characters[s[start_index]];
        } else {
          distinct_characters.erase(s[start_index]);
        }
        ++start_index;
        --current_length;
      }
    }

    return longest_length;
  }
};
// @lc code=end
