/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (39.87%)
 * Likes:    4251
 * Dislikes: 489
 * Total Accepted:    487.1K
 * Total Submissions: 1M
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * Given n non-negative integers a1, a2, ..., an , where each represents a
 * point at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 *
 * Note: You may not slant the container and n is at least 2.
 *
 *
 *
 *
 *
 * The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In
 * this case, the max area of water (blue section) the container can contain is
 * 49.
 *
 *
 *
 * Example:
 *
 *
 * Input: [1,8,6,2,5,4,8,3,7]
 * Output: 49
 */

// @lc code=start
class Solution {
 public:
  int maxArea(vector<int>& heights) {
    int start_index = 0;
    int end_index = heights.size() - 1;
    int width = end_index - start_index;
    int height = std::min(heights[start_index], heights[end_index]);
    int area = width * height;
    int best_area = area;

    while (start_index < end_index) {
      if (heights[start_index] <= heights[end_index]) {
        ++start_index;
      } else {
        --end_index;
      }
      width = end_index - start_index;
      height = std::min(heights[start_index], heights[end_index]);
      area = width * height;
      best_area = std::max(best_area, area);
    }

    return best_area;
  }
};
// @lc code=end
