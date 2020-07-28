/*
 * @lc app=leetcode id=243 lang=cpp
 *
 * [243] Shortest Word Distance
 *
 * https://leetcode.com/problems/shortest-word-distance/description/
 *
 * algorithms
 * Easy (58.52%)
 * Likes:    350
 * Dislikes: 33
 * Total Accepted:    81.9K
 * Total Submissions: 138.1K
 * Testcase Example:  '["practice", "makes", "perfect", "coding",
 * "makes"]\n"coding"\n"practice"'
 *
 * Given a list of words and two words word1 and word2, return the shortest
 * distance between these two words in the list.
 *
 * Example:
 * Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
 *
 *
 * Input: word1 = “coding”, word2 = “practice”
 * Output: 3
 *
 *
 *
 * Input: word1 = "makes", word2 = "coding"
 * Output: 1
 *
 *
 * Note:
 * You may assume that word1 does not equal to word2, and word1 and word2 are
 * both in the list.
 *
 */

// @lc code=start
class Solution {
 public:
  int shortestDistance(vector<string>& words, string word1, string word2) {
    int miminum_distance = INT_MAX;
    for (int i = 0; i < words.size(); ++i) {
      if (words[i] == word1) {
        for (int j = 0; j < words.size(); ++j) {
          if (words[j] == word2) {
            miminum_distance = std::min(miminum_distance, std::abs(j - i));
          }
        }
      }
    }
    return miminum_distance;
  }
};
// @lc code=end
