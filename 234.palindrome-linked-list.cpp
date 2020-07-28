/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (34.45%)
 * Likes:    2098
 * Dislikes: 298
 * Total Accepted:    319.4K
 * Total Submissions: 854.6K
 * Testcase Example:  '[1,2]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 *
 * Example 1:
 *
 *
 * Input: 1->2
 * Output: false
 *
 * Example 2:
 *
 *
 * Input: 1->2->2->1
 * Output: true
 *
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
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
  bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
      return true;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast->next && fast->next->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    bool odd_size = true;
    if (fast->next) {
      odd_size = false;
    }

    ListNode* latter = slow->next;

    ListNode* previous = latter;
    ListNode* current = head;
    while (current != latter) {
      ListNode* old_next = current->next;
      current->next = previous;
      previous = current;
      current = old_next;
    }

    ListNode* former = previous;
    if (odd_size) {
      former = former->next;
    }
    while (latter != nullptr) {
      if (former->val != latter->val) {
        return false;
      }
      former = former->next;
      latter = latter->next;
    }

    return true;
  }
};
// @lc code=end
