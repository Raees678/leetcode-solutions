/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (31.80%)
 * Total Accepted:    1.1M
 * Total Submissions: 3.3M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 * Example:
 *
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 *
 *
 */
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
  // ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  //   ListNode* head = nullptr;
  //   ListNode** current = &head;
  //   int overflowDigit = 0;
  //   int digitCounter = 0;
  //   while (l1 != nullptr || l2 != nullptr) {
  //     int digitValue = overflowDigit;

  //     if (l1) {
  //       digitValue += l1->val;
  //       l1 = l1->next;
  //     }

  //     if (l2) {
  //       digitValue += l2->val;
  //       l2 = l2->next;
  //     }

  //     *current = new ListNode(digitValue % 10);

  //     ++digitCounter;
  //     overflowDigit = digitValue / 10;
  //     current = &((*current)->next);
  //   }

  //   while (overflowDigit) {
  //     (*current)->next = new ListNode(overflowDigit % 10);
  //     (*current) = (*current)->next;
  //     overflowDigit = overflowDigit / 10;
  //   }

  //   return head;
  // }

  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    // IMPORTANT: Please reset any member data you declared, as
    // the same Solution instance will be reused for each test case.
    ListNode *l3;
    ListNode *l;
    int temp = 0;
    int mark = 0;  // mark means a carry digit
    l = l3;        // l=head
    while (l1 || l2) {
      if (l1 && l2) {
        temp = l1->val + l2->val + mark;
        mark = 0;
      }  // sum two digit and carry digit,then reset the carry digit
      if (l1 && !l2) {
        temp = l1->val + mark;
        mark = 0;
      }
      if (!l1 && l2) {
        temp = l2->val + mark;
        mark = 0;
      }
      if (temp > 9) {
        temp = temp - 10;
        mark = 1;
      }  // when the sum bigger than 9,set the carry digit to 1
      ListNode *t = new ListNode(temp);
      l3->next = t;
      l3 = t;
    }
    if (mark) {
      ListNode *tt = new ListNode(mark);
      l3->next = tt;
    }
    return l->next;
  }
};
