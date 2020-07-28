/*
 * [285] Inorder Successor in BST
 *
 * https://leetcode.com/problems/inorder-successor-in-bst/description/
 *
 * algorithms
 * Medium (33.32%)
 * Total Accepted:    80.2K
 * Total Submissions: 240.9K
 * Testcase Example:  '[0]\nnode with value 0'
 *
 * Given a binary search tree and a node in it, find the in-order successor of
 * that node in the BST.
 *
 * Note: If the given node has no in-order successor in the tree, return null.
 *
 * Example 1:
 *empty
 *
 * Input: root = [2,1,3], p = 1
 *
 * ⁠ 2
 * ⁠/ \
 * 1   3
 *
 * Output: 2
 *
 * Example 2:
 *
 *
 * Input: root = [5,3,6,2,4,null,null,1], p = 6
 *
 * ⁠     5
 * ⁠    / \
 * ⁠   3   6
 * ⁠  / \
 * ⁠ 2   4
 * ⁠/
 * 1
 *
 * Output: null
 *
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    // if either root is null or p is null return nullptr
    // nothing to find
    if (!root || !p) {
      return nullptr;
    }
    // keeps track of the successor to the current node
    // initially the current node is assumed to be a single element tree so it
    // is nullptr;

    // basically the immediate successor of a node is either its right child if
    // it exists OR its parent
    // BOTH OF THESE ARE LARGER THAN THE GIVEN NODE
    TreeNode* successor = nullptr;
    while (root) {
      if (root->val <= p->val) {
        root = root->right;
      } else {
        successor = root;
        root = root->left;
      }
    }

    return successor;
  }

  
};
