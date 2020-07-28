/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 *
 * https://leetcode.com/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (40.43%)
 * Likes:    2732
 * Dislikes: 71
 * Total Accepted:    159.1K
 * Total Submissions: 369.1K
 * Testcase Example:  '[1,1,1]\n2'
 *
 * Given an array of integers and an integer k, you need to find the total
 * number of continuous subarrays whose sum equals to k.
 *
 * Example 1:
 *
 * Input:nums = [1,1,1], k = 2
 * Output: 2
 *
 *
 *
 * Note:
 *
 * The length of the array is in range [1, 20,000].
 * The range of numbers in the array is [-1000, 1000] and the range of the
 * integer k is [-1e7, 1e7].
 *
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    std::vector<int> prefix_sums(nums);
    int number_of_subarrays = nums[0] == k ? 1 : 0;
    for (int i = 1; i < prefix_sums.size(); ++i) {
      prefix_sums[i] += prefix_sums[i - 1];
      if (prefix_sums[i] == k) {
        ++number_of_subarrays;
      }
    }

    std::unordered_map<int, int> prefix_sums_count;
    for (int i = 0; i < prefix_sums.size(); ++i) {
      int current_prefix_sum = prefix_sums[i];
      if (prefix_sums_count.find(current_prefix_sum - k) !=
          prefix_sums_count.end()) {
        number_of_subarrays += prefix_sums_count[current_prefix_sum - k];
      }
      ++prefix_sums_count[current_prefix_sum];
    }

    return number_of_subarrays;
  }
};
// @lc code=end
