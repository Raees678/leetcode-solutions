/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 *
 * https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (33.90%)
 * Likes:    1484
 * Dislikes: 299
 * Total Accepted:    215.1K
 * Total Submissions: 559.8K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 *
 * k is a positive integer and is less than or equal to the length of the
 * linked list. If the number of nodes is not a multiple of k then left-out
 * nodes in the end should remain as it is.
 *
 *
 *
 *
 * Example:
 *
 * Given this linked list: 1->2->3->4->5
 *
 * For k = 2, you should return: 2->1->4->3->5
 *
 * For k = 3, you should return: 3->2->1->4->5
 *
 * Note:
 *
 *
 * Only constant extra memory is allowed.
 * You may not alter the values in the list's nodes, only nodes itself may be
 * changed.
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
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head) {
      return head;
    }

    ListNode leading_node(0);
    ListNode* leading_node_ptr = &leading_node;
    leading_node_ptr->next = head;

    ListNode* current_group_begin = head;
    ListNode* current_group_end = head;
    ListNode* previous_group_end = leading_node_ptr;

    while (current_group_begin && current_group_end) {
      int counter = 1;
      while (counter < k && current_group_end) {
        current_group_end = current_group_end->next;
        ++counter;
      }

      if (current_group_end) {
        ListNode* next_group_start = current_group_end->next;
        ListNode* current = current_group_begin;
        ListNode* previous = nullptr;
        ListNode* old_next = current->next;
        while (current != next_group_start) {
          old_next = current->next;
          if (current == current_group_begin) {
            current->next = next_group_start;
          } else {
            current->next = previous;
          }
          if (current == current_group_end) {
            previous_group_end->next = current;
            previous_group_end = current_group_begin;
          }
          previous = current;
          current = old_next;
        }
        current_group_begin = current;
        current_group_end = current;
      }
    }

    ListNode* return_list = leading_node_ptr->next;
    return return_list;
  }
};
// @lc code=end
