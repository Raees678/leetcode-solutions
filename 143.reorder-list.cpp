/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
 *
 * https://leetcode.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (28.61%)
 * Likes:    1177
 * Dislikes: 86
 * Total Accepted:    180.5K
 * Total Submissions: 547K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 *
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 *
 * Example 1:
 *
 *
 * Given 1->2->3->4, reorder it to 1->4->2->3.
 *
 * Example 2:
 *
 *
 * Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
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
#include <iostream>
class Solution {
 public:
  void reorderListRecursive(ListNode* head) {
    if (!head || !(head->next) || !(head->next->next)) {
      return;
    } else {
      ListNode* current = head;
      ListNode* pre_tail = current;
      ListNode* tail = current->next;

      while (tail->next) {
        pre_tail = pre_tail->next;
        tail = tail->next;
      }

      ListNode* old_next = current->next;
      current->next = tail;
      tail->next = old_next;
      current = old_next;
      pre_tail->next = nullptr;
      reorderList(current);
    }
  }

  // this is O(n^2) time
  void reorderListQuadratic(ListNode* head) {
    ListNode* current = head;
    while (current && current->next && current->next->next) {
      ListNode* pre_tail = current;
      ListNode* tail = current->next;

      while (tail->next) {
        pre_tail = pre_tail->next;
        tail = tail->next;
      }

      ListNode* old_next = current->next;
      current->next = tail;
      tail->next = old_next;
      current = old_next;
      pre_tail->next = nullptr;
    }
  }
};
// @lc code=end
