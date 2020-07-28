/*
 * @lc app=leetcode id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/n-ary-tree-level-order-traversal/description/
 *
 * algorithms
 * Easy (55.80%)
 * Likes:    402
 * Dislikes: 37
 * Total Accepted:    56.9K
 * Total Submissions: 91.8K
 * Testcase Example:  '[1,null,3,2,4,null,5,6]\r'
 *
 * Given an n-ary tree, return the level order traversal of its nodes' values.
 *
 * Nary-Tree input serialization is represented in their level order traversal,
 * each group of children is separated by the null value (See examples).
 *
 *
 * Example 1:
 *
 *
 *
 *
 * Input: root = [1,null,3,2,4,null,5,6]
 * Output: [[1],[3,2,4],[5,6]]
 *
 *
 * Example 2:
 *
 *
 *
 *
 * Input: root =
 * [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
 * Output: [[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
 *
 *
 *
 * Constraints:
 *
 *
 * The height of the n-ary tree is less than or equal to 1000
 * The total number of nodes is between [0, 10^4]
 *
 *
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
 public:
  vector<vector<int>> levelOrder(Node* root) {
    std::queue<Node*> queued_nodes;
    std::vector<std::vector<int>> return_vector;
    if (!root) {
      return return_vector;
    }
    queued_nodes.push(root);
    queued_nodes.push(nullptr);
    std::vector<int> current_vector;
    while (!queued_nodes.empty()) {
      Node* current_node = queued_nodes.front();
      queued_nodes.pop();
      if (current_node) {
        current_vector.push_back(current_node->val);
        for (Node* child : current_node->children) {
          queued_nodes.push(child);
        }
      } else {
        if (!queued_nodes.empty()) {
          queued_nodes.push(nullptr);
        }
        if (current_vector.size()) {
          return_vector.push_back(std::move(current_vector));
          current_vector.clear();
        }
      }
    }
    return return_vector;
  }
};
// @lc code=end
