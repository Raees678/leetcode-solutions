/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
 *
 * https://leetcode.com/problems/odd-even-linked-list/description/
 *
 * algorithms
 * Medium (46.84%)
 * Likes:    992
 * Dislikes: 248
 * Total Accepted:    177.5K
 * Total Submissions: 348.3K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given a singly linked list, group all odd nodes together followed by the
 * even nodes. Please note here we are talking about the node number and not
 * the value in the nodes.
 *
 * You should try to do it in place. The program should run in O(1) space
 * complexity and O(nodes) time complexity.
 *
 * Example 1:
 *
 *
 * Input: 1->2->3->4->5->NULL
 * Output: 1->3->5->2->4->NULL
 *
 *
 * Example 2:
 *
 *
 * Input: 2->1->3->5->6->4->7->NULL
 * Output: 2->3->6->7->1->5->4->NULL
 *
 *
 * Note:
 *
 *
 * The relative order inside both the even and odd groups should remain as it
 * was in the input.
 * The first node is considered odd, the second node even and so on ...
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
  ListNode* oddEvenList(ListNode* head) {
    int count = 0;
    ListNode* current = head;
    ListNode* odd_list = nullptr;
    ListNode** odd_list_current = &odd_list;
    ListNode* even_list = nullptr;
    ListNode** even_list_current = &even_list;
    while (current != nullptr) {
      ++count;
      ListNode* next_current = current->next;
      if (count % 2) {
        *odd_list_current = current;
        (*odd_list_current)->next = nullptr;
        odd_list_current = &((*odd_list_current)->next);
      } else {
        *even_list_current = current;
        (*even_list_current)->next = nullptr;
        even_list_current = &((*even_list_current)->next);
      }
      current = next_current;
    }
    *odd_list_current = even_list;
    return odd_list;
  }
};
// @lc code=end
