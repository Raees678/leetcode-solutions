/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 *
 * https://leetcode.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (41.63%)
 * Total Accepted:    108K
 * Total Submissions: 259.2K
 * Testcase Example:  '[1,5,11,5]'
 *
 * Given a non-empty array containing only positive integers, find if the array
 * can be partitioned into two subsets such that the sum of elements in both
 * subsets is equal.
 *
 * Note:
 *
 *
 * Each of the array element will not exceed 100.
 * The array size will not exceed 200.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: [1, 5, 11, 5]
 *
 * Output: true
 *
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 *
 *
 *
 *
 * Example 2:
 *
 *
 * Input: [1, 2, 3, 5]
 *
 * Output: false
 *
 * Explanation: The array cannot be partitioned into equal sum subsets.
 *
 *
 *
 *
 */

#include <cstdlib>
#include <vector>

class Solution {
 public:
  size_t differenceReached(const std::vector<int>& nums, const int& sumToReach,
                           std::vector<std::vector<size_t>>& difference, int i,
                           int j) {
    if (i < 0 || j < 0 || i >= nums.size() || j > sumToReach) {
      return static_cast<size_t>(-1);
    }

    if (difference[i][j] != static_cast<size_t>(-1)) {
      return difference[i][j];
    }

    if (i == nums.size() - 1) {
      // base case: either you include the value at index i to reach the sum j
      // or you dont if it exceeds the sum j
      if (j - nums[i] > 0) {
        difference[i][j] = j - nums[i];
      } else {
        difference[i][j] = j;
      }
    } else {
      // in general the recurrence is
      difference[i][j] = std::min(
          differenceReached(nums, sumToReach, difference, i + 1, j - nums[i]),
          differenceReached(nums, sumToReach, difference, i + 1, j));
    }

    return difference[i][j];
  }

  bool canPartition(vector<int>& nums) {
    int totalSum = std::accumulate(nums.begin(), nums.end(), 0);
    if (totalSum % 2) {
      // if the total sum is odd there is no partition of subsets that can each
      // reach half the totalSum
      return false;
    }

    // otherwise this is an 0/1 knapsack problem
    int sumToReach = totalSum / 2;
    std::vector<std::vector<size_t>> difference(
        nums.size(), std::vector<size_t>(sumToReach + 1, -1));

    size_t minimumDifference = static_cast<size_t>(-1);
    for (int i = nums.size() - 1; i >= 0; --i) {
      for (int j = 0; j < sumToReach + 1; ++j) {
        minimumDifference =
            std::min(differenceReached(nums, sumToReach, difference, i, j),
                     minimumDifference);
      }
    }

    if (difference[0][sumToReach] == 0) {
      return true;
    } else {
      return false;
    }
  }
};
