/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (32.21%)
 * Likes:    3281
 * Dislikes: 374
 * Total Accepted:    522.8K
 * Total Submissions: 1.6M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 *
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 *
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 *
 * You may assume no duplicate exists in the array.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * Example 1:
 *
 *
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 *
 */

// @lc code=start
class Solution {
 public:
  int binarySearchForMin(vector<int>& nums) {
    int low = 0;
    int high = nums.size() - 1;
    int pivot = nums[nums.size() - 1];
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if ((mid == 0 || nums[mid - 1] > nums[mid]) &&
          (mid == nums.size() - 1 || nums[mid] < nums[mid + 1])) {
        return mid;
      } else if (nums[mid] > pivot) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    // should never happen, since there should always be a minimum element
    return -1;
  }

  int binarySearch(vector<int>& nums, int low, int high, int target) {
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] < target) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return -1;
  }

  int search(vector<int>& nums, int target) {
    if (!nums.size()) {
      return -1;
    }
    int min_index = binarySearchForMin(nums);
    int pivot_index = nums.size() - 1;
    int min = nums[min_index];
    int pivot = nums[pivot_index];

    std::cout << "minimum is " << min << " with index " << min_index
              << std::endl;

    if (target > pivot) {
      if (min_index > 0) {
        return binarySearch(nums, 0, min_index - 1, target);
      } else {
        return -1;
      }
    } else {
      // target <= pivot
      return binarySearch(nums, min_index, pivot_index, target);
    }

    // should never be reached
    return -1;
  }
};
// @lc code=end
