/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (28.71%)
 * Likes:    3063
 * Dislikes: 218
 * Total Accepted:    299.1K
 * Total Submissions: 919.3K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given a string S and a string T, find the minimum window in S which will
 * contain all the characters in T in complexity O(n).
 *
 * Example:
 *
 *
 * Input: S = "ADOBECODEBANC", T = "ABC"
 * Output: "BANC"
 *
 *
 * Note:
 *
 *
 * If there is no such window in S that covers all characters in T, return the
 * empty string "".
 * If there is such window, you are guaranteed that there will always be only
 * one unique minimum window in S.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  std::string minWindow(std::string str, std::string pattern) {
    int alphabet_size = 256;

    if (!str.size() || !pattern.size() || str.size() < pattern.size()) {
      return "";
    }

    int string_bitmap[alphabet_size] = {};
    int pattern_bitmap[alphabet_size] = {};
    int number_of_unique_characters = 0;
    for (const char& c : pattern) {
      if (!pattern_bitmap[c]) {
        ++number_of_unique_characters;
      }
      ++pattern_bitmap[c];
    }

    int best_start_index = -1;
    int best_end_index = -1;

    int number_of_unique_characters_matched = 0;
    int start_index = 0;
    int end_index = 0;
    char current_char = str[end_index];
    if (pattern_bitmap[current_char]) {
      ++string_bitmap[current_char];
      if (string_bitmap[current_char] == pattern_bitmap[current_char]) {
        ++number_of_unique_characters_matched;
      }
    }

    while (end_index < str.size()) {
      if (number_of_unique_characters_matched != number_of_unique_characters) {
        ++end_index;
        current_char = str[end_index];
        if (end_index < str.size()) {
          if (pattern_bitmap[current_char]) {
            ++string_bitmap[current_char];
            if (string_bitmap[current_char] == pattern_bitmap[current_char]) {
              ++number_of_unique_characters_matched;
            }
          }
        }
      } else {
        current_char = str[start_index];
        if (best_start_index < 0 ||
            (end_index - start_index + 1) <
                (best_end_index - best_start_index + 1)) {
          best_start_index = start_index;
          best_end_index = end_index;
        }

        if (pattern_bitmap[current_char]) {
          if (string_bitmap[current_char] == pattern_bitmap[current_char]) {
            --number_of_unique_characters_matched;
          }
          --string_bitmap[current_char];
        }
        ++start_index;

        if (end_index < start_index) {
          end_index = start_index;
          if (end_index < str.size()) {
            current_char = str[end_index];
            if (pattern_bitmap[current_char]) {
              ++string_bitmap[current_char];
              if (string_bitmap[current_char] == pattern_bitmap[current_char]) {
                ++number_of_unique_characters_matched;
              }
            }
          }
        }
      }
    }

    while (start_index < str.size() &&
           number_of_unique_characters_matched == number_of_unique_characters) {
      current_char = str[start_index];
      if (best_start_index < 0 || (end_index - start_index + 1) <
                                      (best_end_index - best_start_index + 1)) {
        best_start_index = start_index;
        best_end_index = end_index;
      }

      if (pattern_bitmap[current_char]) {
        if (string_bitmap[current_char] == pattern_bitmap[current_char]) {
          --number_of_unique_characters_matched;
        }
        --string_bitmap[current_char];
      }
      ++start_index;
    }

    if (best_start_index >= 0) {
      return str.substr(best_start_index,
                        best_end_index - best_start_index + 1);
    } else {
      return "";
    }
  }
};
// @lc code=end
