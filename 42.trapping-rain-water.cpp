/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (39.94%)
 * Likes:    4875
 * Dislikes: 86
 * Total Accepted:    380.1K
 * Total Submissions: 833.7K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after raining.
 *
 *
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 * In this case, 6 units of rain water (blue section) are being trapped. Thanks
 * Marcos for contributing this image!
 *
 * Example:
 *
 *
 * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 *
 */

// @lc code=start
class Solution {
 public:
  int trap(vector<int>& height) {
    int water_height = 0;
    int largest_height_from_left = 0;
    int largest_height_from_right = 0;
    int left = 0;
    int right = height.size() - 1;

    while (left <= right) {
      if (largest_height_from_left <= largest_height_from_right) {
        water_height += std::max(largest_height_from_left - height[left], 0);
        largest_height_from_left =
            std::max(largest_height_from_left, height[left]);
        ++left;
      } else {
        water_height += std::max(largest_height_from_right - height[right], 0);
        largest_height_from_right =
            std::max(largest_height_from_right, height[right]);
        --right;
      }
    }

    return water_height;
  }
};
// @lc code=end
