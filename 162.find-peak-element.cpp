/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 *
 * https://leetcode.com/problems/find-peak-element/description/
 *
 * algorithms
 * Medium (39.99%)
 * Likes:    1125
 * Dislikes: 1609
 * Total Accepted:    285.7K
 * Total Submissions: 677.3K
 * Testcase Example:  '[1,2,3,1]'
 *
 * A peak element is an element that is greater than its neighbors.
 *
 * Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element
 * and return its index.
 *
 * The array may contain multiple peaks, in that case return the index to any
 * one of the peaks is fine.
 *
 * You may imagine that nums[-1] = nums[n] = -∞.
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3,1]
 * Output: 2
 * Explanation: 3 is a peak element and your function should return the index
 * number 2.
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,1,3,5,6,4]
 * Output: 1 or 5
 * Explanation: Your function can return either index number 1 where the peak
 * element is 2,
 * or index number 5 where the peak element is 6.
 *
 *
 * Note:
 *
 * Your solution should be in logarithmic complexity.
 *
 */

// @lc code=start
class Solution {
 public:
  int isPeak(vector<int>& nums, int index) {
    bool left_smaller = false;
    bool right_smaller = false;
    if (index == 0 || nums[index] > nums[index - 1]) {
      left_smaller = true;
    }
    if (index == nums.size() - 1 || nums[index] > nums[index + 1]) {
      right_smaller = true;
    }

    if (left_smaller && right_smaller) {
      return 0;
    } else if (left_smaller && !right_smaller) {
      return 1;
    }
    return -1;
  }

  int findPeakElement(vector<int>& nums) {
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high) {
      int mid = low + (high - low) / 2;
      int slope = isPeak(nums, mid);
      if (slope == 0) {
        return mid;
      } else if (slope > 0) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    return -1;
  }
};
// @lc code=end
