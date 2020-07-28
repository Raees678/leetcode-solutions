/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 *
 * https://leetcode.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (43.23%)
 * Likes:    2130
 * Dislikes: 180
 * Total Accepted:    374.9K
 * Total Submissions: 857.6K
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * Given an array with n objects colored red, white or blue, sort them in-place
 * so that objects of the same color are adjacent, with the colors in the order
 * red, white and blue.
 *
 * Here, we will use the integers 0, 1, and 2 to represent the color red,
 * white, and blue respectively.
 *
 * Note: You are not suppose to use the library's sort function for this
 * problem.
 *
 * Example:
 *
 *
 * Input: [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 *
 * Follow up:
 *
 *
 * A rather straight forward solution is a two-pass algorithm using counting
 * sort.
 * First, iterate the array counting number of 0's, 1's, and 2's, then
 * overwrite array with total number of 0's, then 1's and followed by 2's.
 * Could you come up with a one-pass algorithm using only constant space?
 *
 *
 */

// @lc code=start
class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int pivot = 1;
    int low_boundary_index = 0;
    int high_boundary_index = nums.size() - 1;

    int current_index = 0;
    while (current_index <= high_boundary_index) {
      int current_value = nums[current_index];
      if (current_value < pivot) {
        int low_boundary_value = nums[low_boundary_index];
        nums[low_boundary_index] = current_value;
        nums[current_index] = low_boundary_value;
        ++low_boundary_index;
        ++current_index;
      } else if (current_value > pivot) {
        int high_boundary_value = nums[high_boundary_index];
        nums[high_boundary_index] = current_value;
        nums[current_index] = high_boundary_value;
        --high_boundary_index;
      } else {
        ++current_index;
      }
    }
  }
};
// @lc code=end
