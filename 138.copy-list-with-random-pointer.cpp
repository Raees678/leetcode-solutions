/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 *
 * https://leetcode.com/problems/copy-list-with-random-pointer/description/
 *
 * algorithms
 * Medium (25.56%)
 * Likes:    2081
 * Dislikes: 512
 * Total Accepted:    300.7K
 * Total Submissions: 1M
 * Testcase Example:
 * '{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}'
 *
 * A linked list is given such that each node contains an additional random
 * pointer which could point to any node in the list or null.
 *
 * Return a deep copy of the list.
 *
 *
 *
 * Example 1:
 *
 *
 *
 *
 * Input:
 *
 * {"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}
 *
 * Explanation:
 * Node 1's value is 1, both of its next and random pointer points to Node 2.
 * Node 2's value is 2, its next pointer points to null and its random pointer
 * points to itself.
 *
 *
 *
 *
 * Note:
 *
 *
 * You must return the copy of the given head as a reference to the cloned
 * list.
 *
 *
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/

#include <unordered_map>
class Solution {
 public:
  Node* copyRandomList(Node* head) {
    std::unordered_map<Node*, Node*> previouslyAddedNodes;
    Node* return_list = nullptr;
    Node** current = &return_list;
    while (head) {
      (*current) = new Node(head->val, head->next, head->random);
      previouslyAddedNodes[head] = (*current);
      head = head->next;
      current = &((*current)->next);
    }

    current = &return_list;
    while (*current) {
      (*current)->random = previouslyAddedNodes[(*current)->random];
      current = &((*current)->next);
    }
    return return_list;
  }
};
// @lc code=end
