/*
 * @lc app=leetcode id=430 lang=cpp
 *
 * [430] Flatten a Multilevel Doubly Linked List
 *
 * https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/description/
 *
 * algorithms
 * Medium (36.16%)
 * Likes:    563
 * Dislikes: 92
 * Total Accepted:    39.8K
 * Total Submissions: 87.8K
 * Testcase Example:
 *
 * You are given a doubly linked list which in addition to the next and
 * previous pointers, it could have a child pointer, which may or may not point
 * to a separate doubly linked list. These child lists may have one or more
 * children of their own, and so on, to produce a multilevel data structure, as
 * shown in the example below.
 *
 * Flatten the list so that all the nodes appear in a single-level, doubly
 * linked list. You are given the head of the first level of the list.
 *
 *
 *
 * Example:
 *
 *
 * Input:
 * ⁠1---2---3---4---5---6--NULL
 * ⁠        |
 * ⁠        7---8---9---10--NULL
 * ⁠            |
 * ⁠            11--12--NULL
 *
 * Output:
 * 1-2-3-7-8-11-12-9-10-4-5-6-NULL
 *
 *
 *
 *
 * Explanation for the above example:
 *
 * Given the following multilevel doubly linked list:
 *
 *
 *
 *
 *
 *
 * We should return the following flattened doubly linked list:
 *
 *
 *
 *
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
 public:
  Node* flattenDelegate(Node* head, Node* next_link) {
    Node* current = head;
    while (current->next) {
      if (current->child) {
        Node* old_next = current->next;
        current->next = current->child;
        current->child->prev = current;
        current->child = nullptr;
        current = flattenDelegate(current->next, old_next);
      } else {
        current = current->next;
      }
    }

    if (current->child) {
      Node* old_next = current->next;
      current->next = current->child;
      current->child->prev = current;
      current->child = nullptr;
      current = flattenDelegate(current->next, old_next);
    }

    current->next = next_link;
    if (current->next) {
      current->next->prev = current;
    }
    return current;
  }

  Node* flattenRecursive(Node* head) {
    if (!head) {
      return head;
    }
    flattenDelegate(head, nullptr);
    Node* current = head;
    return head;
  }

  Node* flatten(Node* head) {
    ;
    ;
    ;
    ;
  }
};
// @lc code=end
