/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 *
 * https://leetcode.com/problems/word-break/description/
 *
 * algorithms
 * Medium (33.04%)
 * Likes:    3025
 * Dislikes: 166
 * Total Accepted:    423.8K
 * Total Submissions: 1.1M
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * Given a non-empty string s and a dictionary word_dict containing a list of
 * non-empty words, determine if s can be segmented into a space-separated
 * sequence of one or more dictionary words.
 *
 * Note:
 *
 *
 * The same word in the dictionary may be reused multiple times in the
 * segmentation.
 * You may assume the dictionary does not contain duplicate words.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "leetcode", word_dict = ["leet", "code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet
 * code".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "applepenapple", word_dict = ["apple", "pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple
 * pen apple".
 * Note that you are allowed to reuse a dictionary word.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "catsandog", word_dict = ["cats", "dog", "sand", "and", "cat"]
 * Output: false
 *
 *
 */

// @lc code=start
class Solution {
 public:
  // state of a given index in the string
  // EITHER an index is unvisited i.e. no other strings from that index have
  // been considered as words
  // OR it has been visited and possible words have been found in the
  // dictionary from that index forward
  // OR it has been visited and no words in the dictionary have been found from
  // that index
  enum state { UNVISITED, FOUND, NOT_FOUND };

  bool wordExists(const string& word, const vector<string>& word_dict) {
    for (string s : word_dict) {
      if (word == s) {
        return true;
      }
    }
    return false;
  }

  bool wordBreakHelper(string s, int start_index, vector<string>& word_dict,
                       vector<state>& memo) {
    if (start_index == s.size()) {
      return true;
    }

    // this start_index has been visited before and no words have been found
    // in the dictionary from this index forward
    if (memo[start_index] == NOT_FOUND) {
      return false;
    }

    for (int end_index = start_index; end_index < s.size(); ++end_index) {
      string prefix = s.substr(start_index, end_index - start_index + 1);
      if (wordExists(prefix, word_dict)) {
        memo[start_index] = FOUND;
        bool matched_till_end =
            wordBreakHelper(s, end_index + 1, word_dict, memo);
        if (matched_till_end) {
          return true;
        }
      }
    }
    // if you get till this point then no words in the dictionary have been
    // found from that index forward
    memo[start_index] = NOT_FOUND;
    return false;
  }

  bool wordBreak(string s, vector<string>& word_dict) {
    vector<state> memo(s.size(), UNVISITED);
    return wordBreakHelper(s, 0, word_dict, memo);
  }
};
// @lc code=end
