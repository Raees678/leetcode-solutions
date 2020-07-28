/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 *
 * https://leetcode.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (32.34%)
 * Likes:    1845
 * Dislikes: 95
 * Total Accepted:    214.9K
 * Total Submissions: 565.6K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Sort a linked list in O(n log n) time using constant space complexity.
 *
 * Example 1:
 *
 *
 * Input: 4->2->1->3
 * Output: 1->2->3->4
 *
 *
 * Example 2:
 *
 *
 * Input: -1->5->3->4->0
 * Output: -1->0->3->4->5
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
  ListNode* merge(ListNode* first, ListNode* second) {
    ListNode* return_list = nullptr;

    ListNode** current = &return_list;
    while (first && second) {
      if (first->val <= second->val) {
        *current = first;
        first = first->next;
      } else {
        *current = second;
        second = second->next;
      }
      current = &((*current)->next);
    }

    if (first) {
      *current = first;
    } else {
      (*current) = second;
    }

    return return_list;
  }

  ListNode* divide(ListNode* head) {
    if (head->next) {
      ListNode* slow_ptr = head;
      ListNode* fast_ptr = head;
      while (fast_ptr->next && fast_ptr->next->next) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
      }
      ListNode* first = head;
      ListNode* second = slow_ptr->next;
      slow_ptr->next = nullptr;
      if (fast_ptr->next) {
        fast_ptr->next->next = nullptr;
      }

      first = divide(first);
      second = divide(second);
      return merge(first, second);
    } else {
      return head;
    }
  }

  ListNode* sortList(ListNode* head) {
    if (!head) {
      return head;
    }

    ListNode* sorted = divide(head);
    return sorted;
  }
};
// @lc code=end
