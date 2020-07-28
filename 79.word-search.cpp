/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (29.29%)
 * Likes:    2473
 * Dislikes: 130
 * Total Accepted:    360K
 * Total Submissions: 1.1M
 * Testcase Example:
 * '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 *
 * Example:
 *
 *
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 *
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  bool existHelper(std::vector<std::vector<char>>& board, int row, int col,
                   string word, int word_index) {
    if (board[row][col] == word[word_index]) {
      ++word_index;
      char temp_char = board[row][col];
      board[row][col] = '$';

      if (word_index == word.size()) {
        return true;
      }

      if (row + 1 < board.size()) {
        bool exists = existHelper(board, row + 1, col, word, word_index);
        if (exists) {
          return true;
        }
      }

      if (row - 1 >= 0) {
        bool exists = existHelper(board, row - 1, col, word, word_index);
        if (exists) {
          return true;
        }
      }

      if (col + 1 < board[row].size()) {
        bool exists = existHelper(board, row, col + 1, word, word_index);
        if (exists) {
          return true;
        }
      }

      if (col - 1 >= 0) {
        bool exists = existHelper(board, row, col - 1, word, word_index);
        if (exists) {
          return true;
        }
      }
      board[row][col] = temp_char;
    }

    return false;
  }

  bool exist(std::vector<std::vector<char>>& board, string word) {
    std::vector<std::vector<bool>> visited(
        board.size(), std::vector<bool>(board[0].size(), false));

    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[i].size(); ++j) {
        bool exists = existHelper(board, i, j, word, 0);
        if (exists) {
          return true;
        }
      }
    }

    return false;
  }
};
// @lc code=end
