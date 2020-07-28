/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 *
 * https://leetcode.com/problems/edit-distance/description/
 *
 * algorithms
 * Hard (34.83%)
 * Likes:    2866
 * Dislikes: 44
 * Total Accepted:    216.9K
 * Total Submissions: 531.9K
 * Testcase Example:  '"horse"\n"ros"'
 *
 * Given two words word_1 and word_2, find the minimum number of operations
 * required to convert word_1 to word_2.
 *
 * You have the following 3 operations permitted on a word:
 *
 *
 * Insert a character
 * Delete a character
 * Replace a character
 *
 *
 * Example 1:
 *
 *
 * Input: word_1 = "horse", word_2 = "ros"
 * Output: 3
 * Explanation:
 * horse -> rorse (replace 'h' with 'r')
 * rorse -> rose (remove 'r')
 * rose -> ros (remove 'e')
 *
 *
 * Example 2:
 *
 *
 * Input: word_1 = "intention", word_2 = "execution"
 * Output: 5
 * Explanation:
 * intention -> inention (remove 't')
 * inention -> enention (replace 'i' with 'e')
 * enention -> exention (replace 'n' with 'x')
 * exention -> exection (replace 'n' with 'c')
 * exection -> execution (insert 'u')
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int getDistance(const std::string& word_1, int index_1,
                  const std::string& word_2, int index_2,
                  std::vector<std::vector<int>>& best_distance) {
    // if index_2 is at the end of word_2 then that means the whole word_2
    // is matched
    if (index_1 == word_1.size() || index_2 == word_2.size()) {
      return word_1.size() - index_1 + word_2.size() - index_2;
    }

    // if the best distance between word_1 and word_2 has been previously
    // computed simply return that
    if (best_distance[index_1][index_2] != -1) {
      return best_distance[index_1][index_2];
    }

    int deletion_d = INT_MAX;
    int replacement_d = INT_MAX;
    int insertion_d = INT_MAX;
    int unchanged_d = INT_MAX;

    deletion_d =
        1 + getDistance(word_1, index_1 + 1, word_2, index_2, best_distance);
    replacement_d = 1 + getDistance(word_1, index_1 + 1, word_2, index_2 + 1,
                                    best_distance);
    unchanged_d =
        getDistance(word_1, index_1 + 1, word_2, index_2 + 1, best_distance);
    insertion_d =
        1 + getDistance(word_1, index_1, word_2, index_2 + 1, best_distance);

    int min_distance =
        std::min({deletion_d, replacement_d, insertion_d, unchanged_d});

    best_distance[index_1][index_2] = min_distance;
    return min_distance;
  }

  int minDistance(std::string word_1, std::string word_2) {
    std::vector<std::vector<int>> best_distance(
        word_1.size(), std::vector<int>(word_2.size(), -1));
    getDistance(word_1, 0, word_2, 0, best_distance);
    return best_distance[0][0];
  }
};
// @lc code=end
