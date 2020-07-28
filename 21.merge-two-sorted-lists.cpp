/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (43.85%)
 * Likes:    2839
 * Dislikes: 413
 * Total Accepted:    731.6K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 *
 * Example:
 *
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 *
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* return_list = nullptr;
    ListNode** current = &return_list;
    while (l1 != nullptr && l2 != nullptr) {
      if (l1->val <= l2->val) {
        *current = l1;
        l1 = l1->next;
      } else {
        *current = l2;
        l2 = l2->next;
      }
      (*current)->next = nullptr;
      current = &((*current)->next);
    }

    if (l1) {
      *current = l1;
    } else {
      *current = l2;
    }

    return return_list;
  }
};
// @lc code=end
