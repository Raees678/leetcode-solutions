/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 *
 * https://leetcode.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (31.43%)
 * Total Accepted:    151.9K
 * Total Submissions: 444.3K
 * Testcase Example:
 * '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square
 * containing only 1's and return its area.
 *
 * Example:
 *
 *
 * Input:
 *
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 *
 * Output: 4
 *
 */
class Solution {
 public:
  maximalSquareCalculator() {}

  int maximalSquare(std::vector<std::vector<char>>& matrix) {
    int largestSquareSize = 0;
    std::vector<int> largestSquareForPreviousLine(matrix.size(), 0);
    int largestSquareForPreviousIndex = 0;
  }
};
