/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 *
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (32.92%)
 * Likes:    1554
 * Dislikes: 108
 * Total Accepted:    223.3K
 * Total Submissions: 612.9K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * Reverse a linked list from position m to n. Do it in one-pass.
 *
 * Note: 1 ≤ m ≤ n ≤ length of list.
 *
 * Example:
 *
 *
 * Input: 1->2->3->4->5->NULL, m = 2, n = 4
 * Output: 1->4->3->2->5->NULL
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
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode* return_list = nullptr;
    ListNode** current = &return_list;

    int counter = 1;
    while (counter < m) {
      *current = head;
      head = head->next;
      (*current)->next = nullptr;
      current = &((*current)->next);
      ++counter;
    }

    ListNode** suffix = nullptr;
    while (counter <= n) {
      ListNode* old_current = *current;
      *current = head;
      head = head->next;
      (*current)->next = old_current;
      if (!old_current) {
        suffix = &((*current)->next);
      }
      ++counter;
    }

    *suffix = head;

    return return_list;
  }
};
// @lc code=end
