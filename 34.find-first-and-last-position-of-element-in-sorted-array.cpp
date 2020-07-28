/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-last-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (32.23%)
 * Likes:    2236
 * Dislikes: 106
 * Total Accepted:    381.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].
 *
 * Example 1:
 *
 *
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 *
 * Example 2:
 *
 *
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 *
 */

// @lc code=start
class Solution {
 public:
  int binarySearchLast(std::vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (nums[mid] < target || nums[mid] == target && mid < nums.size() - 1 &&
                                    nums[mid + 1] == target) {
        low = mid + 1;
      } else if (nums[mid] > target) {
        high = mid - 1;
      } else {
        return mid;
      }
    }

    return -1;
  }

  int binarySearchFirst(std::vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (nums[mid] < target) {
        low = mid + 1;
      } else if (nums[mid] > target ||
                 nums[mid] == target && mid > 0 && nums[mid - 1] == target) {
        high = mid - 1;
      } else {
        return mid;
      }
    }

    return -1;
  }

  vector<int> searchRange(vector<int>& nums, int target) {
    int first = binarySearchFirst(nums, target);
    int last = binarySearchLast(nums, target);
    return std::vector<int>{first, last};
  }
};
// @lc code=end
