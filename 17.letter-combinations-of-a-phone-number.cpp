/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (38.75%)
 * Likes:    2826
 * Dislikes: 351
 * Total Accepted:    483.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 *
 *
 *
 * Example:
 *
 *
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 *
 *
 * Note:
 *
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 *
 */

// @lc code=start
class Solution {
 public:
  std::vector<std::vector<char>> digit_to_letter_ = {{},
                                                     {},
                                                     {'a', 'b', 'c'},
                                                     {'d', 'e', 'f'},
                                                     {'g', 'h', 'i'},
                                                     {'j', 'k', 'l'},
                                                     {'m', 'n', 'o'},
                                                     {'p', 'q', 'r', 's'},
                                                     {'t', 'u', 'v'},
                                                     {'w', 'x', 'y', 'z'}};

  void letterCombinationsHelper(std::string digits, std::string buffer,
                                int digits_index, int buffer_index,
                                std::vector<string>& return_vector) {
    if (buffer_index == buffer.size()) {
      return_vector.push_back(buffer);
      return;
    }

    int digit = digits[digits_index] - '0';

    for (int i = 0; i < digit_to_letter_[digit].size(); ++i) {
      char letter = digit_to_letter_[digit][i];
      buffer[buffer_index] = letter;
      letterCombinationsHelper(digits, buffer, digits_index + 1,
                               buffer_index + 1, return_vector);
    }
    return;
  }

  vector<string> letterCombinations(std::string digits) {
    std::vector<string> return_vector;
    if (!digits.size()) {
      return return_vector;
    }

    std::string buffer(digits.size(), '\0');
    letterCombinationsHelper(digits, buffer, 0, 0, return_vector);
    return return_vector;
  }
};
// @lc code=end
