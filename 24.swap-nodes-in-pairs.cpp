/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (41.48%)
 * Likes:    1493
 * Dislikes: 136
 * Total Accepted:    372.4K
 * Total Submissions: 792.7K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 *
 *
 *
 * Example:
 *
 *
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
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
  ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) {
      return head;
    }

    ListNode* return_list = nullptr;
    ListNode** current = &return_list;
    while (head != nullptr) {
      ListNode* first_node = head;
      ListNode* second_node = head->next;

      if (head->next) {
        head = head->next->next;
      } else {
        head = head->next;
      }
      if (second_node) {
        *current = second_node;
        (*current)->next = first_node;
        (*current)->next->next = nullptr;
        current = &((*current)->next->next);
      } else {
        *current = first_node;
        (*current)->next = nullptr;
        current = &((*current)->next);
      }
    }

    return return_list;
  }
};
// @lc code=end
