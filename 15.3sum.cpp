/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (22.32%)
 * Likes:    4876
 * Dislikes: 581
 * Total Accepted:    700K
 * Total Submissions: 2.8M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 *
 * Note:
 *
 * The solution set must not contain duplicate triplets.
 *
 * Example:
 *
 *
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 *                    [-4, -1, -1, 0, 1, 2]
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 *
 */

// @lc code=start
class Solution {
 public:
  void increment(int& i, const std::vector<int>& nums, const int& used_index) {
    ++i;
    while (nums[i] == nums[i - 1] || i == used_index) {
      ++i;
    }
  }

  void decrement(int& i, const std::vector<int>& nums, const int& used_index) {
    --i;
    while (nums[i] == nums[i + 1] || i == used_index) {
      --i;
    }
  }

  bool twoSum(std::vector<int>& nums, int target_sum, int used_index,
              std::vector<int>& result) {
    int start = 0;
    if (start == used_index) {
      ++start;
    }

    int end = nums.size() - 1;
    if (end == used_index) {
      --end;
    }

    int reached_sum = nums[start] + nums[end];
    while (start < end && reached_sum != target_sum) {
      std::cout << "checking " << start << ": " << nums[start] << ", " << end
                << ": " << nums[end] << std::endl;
      if (reached_sum < target_sum) {
        // increment start
        increment(start, nums, used_index);
      } else if (reached_sum > target_sum) {
        // decrement end
        decrement(end, nums, used_index);
      }
      reached_sum = nums[start] + nums[end];
    }

    if (start < end && reached_sum == target_sum) {
      result[1] = nums[start];
      result[2] = nums[end];
      return true;
    }
    return false;
  }

  std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<int> result(3, 0);
    std::vector<vector<int>> return_vector;

    for (int i = 0; i < nums.size(); ++i) {
      int used_number = nums[i];
      int used_index = i;
      int target_sum = -1 * used_number;
      std::cout << "selected index: " << i << " with number: " << used_number
                << std::endl;

      result[0] = used_number;
      bool successful = twoSum(nums, target_sum, used_index, result);
      if (successful) {
        std::cout << "found 2 other numbers using 2sum" << std::endl;
        std::cout << result[0] << ", " << result[1] << ", " << result[2]
                  << std::endl;

        return_vector.push_back(result);
      }
    }

    return return_vector;
  }
};
// @lc code=end
