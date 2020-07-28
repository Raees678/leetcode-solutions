/*
 * [62] Unique Paths
 *
 * https://leetcode.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (44.87%)
 * Total Accepted:    230K
 * Total Submissions: 512.5K
 * Testcase Example:  '3\n2'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 *
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 *
 * How many possible unique paths are there?
 *
 *
 * Above is a 7 x 3 grid. How many possible unique paths are there?
 *
 * Note: m and n will be at most 100.
 *
 * Example 1:
 *
 *
 * Input: m = 3, n = 2
 * Output: 3
 * Explanation:
 * From the top-left corner, there are a total of 3 ways to reach the
 * bottom-right corner:
 * 1. Right -> Right -> Down
 * 2. Right -> Down -> Right
 * 3. Down -> Right -> Right
 *
 *
 * Example 2:
 *
 *
 * Input: m = 7, n = 3
 * Output: 28
 *
 */

#include <cmath>

class Solution {
 public:
  int uniquePaths(int m, int n) {
    // there are m + n - 2 total moves to make i.e. (m + n - 2)!
    // in those there are m repititions of m - 1 repititions of down and n - 1
    // repititoins of right
    // return value = (m + n - 2)!/((m - 1)!*(n - 1)!)
    // FACTORIALS MEANS THINK OF OVERFLOWS

    --m;
    --n;
    double lesser = m;
    double greater = n;
    double result = 1;
    for (int i = 1; i <= lesser; ++i) {
      result = result * ((greater + i) / (i));
    };

    return round(result);
  }
};
