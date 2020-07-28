/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 *
 * https://leetcode.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (39.97%)
 * Likes:    1646
 * Dislikes: 207
 * Total Accepted:    483.4K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * Given a sorted array and a target value, return the index if the target is
 * found. If not, return the index where it would be if it were inserted in
 * order.
 *
 * You may assume no duplicates in the array.
 *
 * Example 1:
 *
 *
 * Input: [1,3,5,6], 5
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: [1,3,5,6], 2
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: [1,3,5,6], 7
 * Output: 4
 *
 *
 * Example 4:
 *
 *
 * Input: [1,3,5,6], 0
 * Output: 0
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (nums[mid] < target) {
        if (mid == nums.size() - 1) {
          return nums.size();
        }
        low = mid + 1;
      } else if (nums[mid] > target) {
        if (mid == 0 || nums[mid - 1] < target) {
          return mid;
        }
        high = mid - 1;
      } else {
        return mid;
      }
    }
    return -1;
  }
};
// @lc code=end
