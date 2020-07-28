/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 *
 * https://leetcode.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (56.67%)
 * Likes:    520
 * Dislikes: 933
 * Total Accepted:    273.6K
 * Total Submissions: 472.5K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * Given two arrays, write a function to compute their intersection.
 *
 * Example 1:
 *
 *
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [9,4]
 *
 *
 * Note:
 *
 *
 * Each element in the result must be unique.
 * The result can be in any order.
 *
 *
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    std::unordered_set<int> unique_nums2;
    for (int& i : nums2) {
      unique_nums2.insert(i);
    }

    std::unordered_set<int> unique_nums1;
    std::vector<int> return_vector;
    for (int& i : nums1) {
      if (unique_nums2.find(i) != unique_nums2.end()) {
        if (unique_nums1.find(i) == unique_nums1.end()) {
          unique_nums1.insert(i);
          return_vector.push_back(i);
        }
      }
    }

    return return_vector;
  }
};
// @lc code=end
