/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 *
 * https://leetcode.com/problems/linked-list-cycle-ii/description/
 *
 * algorithms
 * Medium (29.86%)
 * Likes:    1872
 * Dislikes: 148
 * Total Accepted:    254.1K
 * Total Submissions: 743.2K
 * Testcase Example:  '[3,2,0,-4]\n1'
 *
 * Given a linked list, return the node where the cycle begins. If there is no
 * cycle, return null.
 *
 * To represent a cycle in the given linked list, we use an integer pos which
 * represents the position (0-indexed) in the linked list where tail connects
 * to. If pos is -1, then there is no cycle in the linked list.
 *
 * Note: Do not modify the linked list.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: head = [3,2,0,-4], pos = 1
 * Output: tail connects to node index 1
 * Explanation: There is a cycle in the linked list, where tail connects to the
 * second node.
 *
 *
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1,2], pos = 0
 * Output: tail connects to node index 0
 * Explanation: There is a cycle in the linked list, where tail connects to the
 * first node.
 *
 *
 *
 *
 * Example 3:
 *
 *
 * Input: head = [1], pos = -1
 * Output: no cycle
 * Explanation: There is no cycle in the linked list.
 *
 *
 *
 *
 *
 *
 * Follow-up:
 * Can you solve it without using extra space?
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
  ListNode* detectCycle(ListNode* head) {
    if (!head) {
      return head;
    }

    ListNode* slow = head;
    ListNode* fast = head;
    bool are_same = false;
    while (fast->next && fast->next->next && !are_same) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        are_same = true;
      }
    }

    if (!fast->next || !fast->next->next) {
      return nullptr;
    }

    // at this point a cycle must exist and slow == fast

    // there exists at least 1 node in the cycle i.e. slow
    int cycle_length = 1;
    fast = fast->next;
    while (fast != slow) {
      fast = fast->next;
      ++cycle_length;
    }

    // cycle_length now holds the number of nodes in the cycle
    // travelling cycle_length links from a node in the cycle leads abck to the
    // original node
    // so have two pointers cycle_length links apart and then move them until
    // they equal each other. that is the first node in the cycle

    slow = head;
    fast = slow;

    for (int i = 0; i < cycle_length; ++i) {
      fast = fast->next;
    }

    while (slow != fast) {
      slow = slow->next;
      fast = fast->next;
    }

    return slow;
  }
};
// @lc code=end
