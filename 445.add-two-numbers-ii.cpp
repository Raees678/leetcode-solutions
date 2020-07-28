/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
 *
 * https://leetcode.com/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (51.28%)
 * Likes:    922
 * Dislikes: 123
 * Total Accepted:    114K
 * Total Submissions: 220.3K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The most significant digit comes first and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 * Follow up:
 * What if you cannot modify the input lists? In other words, reversing the
 * lists is not allowed.
 *
 *
 *
 * Example:
 *
 * Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 8 -> 0 -> 7
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
 private:
  ListNode* reverseListOrdering(ListNode* list_head) {
    ListNode* list_reverse_head = nullptr;
    while (list_head) {
      ListNode* prev_list_reverse_head = list_reverse_head;
      list_reverse_head = list_head;
      list_head = list_head->next;
      list_reverse_head->next = prev_list_reverse_head;
    }

    return list_reverse_head;
  }

 public:
  ListNode* addTwoNumbers(ListNode* l1_head, ListNode* l2_head) {
    ListNode* l1_reverse_head = reverseListOrdering(l1_head);
    ListNode* l2_reverse_head = reverseListOrdering(l2_head);
    ListNode* l3_reverse_head = nullptr;
    ListNode** l3_current = &l3_reverse_head;
    int overflow = 0;

    while (l1_reverse_head || l2_reverse_head) {
      int totalSum = overflow;
      if (l1_reverse_head) {
        totalSum += l1_reverse_head->val;
        l1_reverse_head = l1_reverse_head->next;
      }
      if (l2_reverse_head) {
        totalSum += l2_reverse_head->val;
        l2_reverse_head = l2_reverse_head->next;
      }

      *l3_current = new ListNode(totalSum % 10);
      l3_current = &((*l3_current)->next);
      overflow = totalSum / 10;
    }

    while (overflow > 0) {
      *l3_current = new ListNode(overflow % 10);
      l3_current = &((*l3_current)->next);
      overflow = overflow / 10;
    }

    return reverseListOrdering(l3_reverse_head);
  }
};
// @lc code=end
