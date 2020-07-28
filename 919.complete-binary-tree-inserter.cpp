/*
 * [955] Complete Binary Tree Inserter
 *
 * https://leetcode.com/problems/complete-binary-tree-inserter/description/
 *
 * algorithms
 * Medium (54.43%)
 * Total Accepted:    3.7K
 * Total Submissions: 6.8K
 * Testcase Example:  '["CBTInserter","insert","get_root"]\n[[[1]],[2],[]]'
 *
 * A complete binary tree is a binary tree in which every level, except
 * possibly the last, is completely filled, and all nodes are as far left as
 * possible.
 *
 * Write a data structure CBTInserter that is initialized with a complete
 * binary tree and supports the following operations:
 *
 *
 * CBTInserter(TreeNode root) initializes the data structure on a given tree
 * with head node root;
 * CBTInserter.insert(int v) will insert a TreeNode into the tree with value
 * node.val = v so that the tree remains complete, and returns the value of the
 * parent of the inserted TreeNode;
 * CBTInserter.get_root() will return the head node of the tree.
 *
 *
 *
 *
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: inputs = ["CBTInserter","insert","get_root"], inputs = [[[1]],[2],[]]
 * Output: [null,1,[1,2]]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: inputs = ["CBTInserter","insert","insert","get_root"], inputs =
 * [[[1,2,3,4,5,6]],[7],[8],[]]
 * Output: [null,3,4,[1,2,3,4,5,6,7,8]]
 *
 *
 *
 *
 *
 * Note:
 *
 *
 * The initial given tree is complete and contains between 1 and 1000
 * nodes.
 * CBTInserter.insert is called at most 10000 times per test case.
 * Every value of a given or inserted node is between 0 and 5000.
 *
 *
 *
 *
 *
 *
 *
 *
 *
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

#include <queue>
class CBTInserter {
 public:
  CBTInserter(TreeNode* root) : root_(root){};

  int insert(int v) {
    // Each node either has 2 children or 0 in a complete binary tree
    // Find the first node with less than 2 children using BFS
    TreeNode* parentNode = BFSSearch();
    if (parentNode->left) {
      parentNode->right = new TreeNode(v);
    } else {
      parentNode->left = new TreeNode(v);
    }
    return parentNode->val;
  }

  TreeNode* BFSSearch() {
    std::queue<TreeNode*> q;
    q.push(root_);

    while (!q.empty()) {
      TreeNode* currentNode = q.front();
      q.pop();
      int numberOfChildren = 0;
      if (currentNode->left) {
        ++numberOfChildren;
        q.push(currentNode->left);
      }
      if (currentNode->right) {
        ++numberOfChildren;
        q.push(currentNode->right);
      }
      if (numberOfChildren < 2) {
        return currentNode;
      }
    }
  }

  TreeNode* get_root() { return root_; }

  TreeNode* root_;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter obj = new CBTInserter(root);
 * int param_1 = obj.insert(v);
 * TreeNode* param_2 = obj.get_root();
 */
