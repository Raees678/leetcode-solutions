/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 *
 * https://leetcode.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (50.38%)
 * Likes:    3007
 * Dislikes: 75
 * Total Accepted:    729.6K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Reverse a singly linked list.
 *
 * Example:
 *
 *
 * Input: 1->2->3->4->5->NULL
 * Output: 5->4->3->2->1->NULL
 *
 *
 * Follow up:
 *
 * A linked list can be reversed either iteratively or recursively. Could you
 * implement both?
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
  ListNode* reverseList(ListNode* head) {
    ListNode* return_list = nullptr;
    ListNode** current = &return_list;

    while (head != nullptr) {
      ListNode* old_current = *current;
      *current = head;
      head = head->next;
      (*current)->next = old_current;
    }

    return return_list;
  }
};
// @lc code=end
