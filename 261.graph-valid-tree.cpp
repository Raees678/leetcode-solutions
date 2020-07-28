/*
 * @lc app=leetcode id=261 lang=cpp
 *
 * [261] Graph Valid Tree
 *
 * https://leetcode.com/problems/graph-valid-tree/description/
 *
 * algorithms
 * Medium (38.97%)
 * Likes:    852
 * Dislikes: 29
 * Total Accepted:    113K
 * Total Submissions: 274.6K
 * Testcase Example:  '5\n[[0,1],[0,2],[0,3],[1,4]]'
 *
 * Given n nodes labeled from 0 to n-1 and a list of undirected edges (each
 * edge is a pair of nodes), write a function to check whether these edges make
 * up a valid tree.
 *
 * Example 1:
 *
 *
 * Input: n = 5, and edges = [[0,1], [0,2], [0,3], [1,4]]
 * Output: true
 *
 * Example 2:
 *
 *
 * Input: n = 5, and edges = [[0,1], [1,2], [2,3], [1,3], [1,4]]
 * Output: false
 *
 * Note: you can assume that no duplicate edges will appear in edges. Since all
 * edges are undirected, [0,1] is the same as [1,0] and thus will not appear
 * together in edges.
 *
 */

// @lc code=start
class Solution {
 public:
  enum color { BLACK, GREY, WHITE };
  bool dfsCycleFound(int node, int parent,
                     const std::vector<std::vector<int>>& graph,
                     std::vector<color>& state) {
    // if a node has been previously visited or visiting then there exists a
    // cycle
    if (state[node] != WHITE) {
      return true;
    }
    state[node] = GREY;
    bool cycle_found = false;
    for (int i = 0; i < graph[node].size(); ++i) {
      const int neighbour = graph[node][i];
      if (neighbour != parent) {
        cycle_found = dfsCycleFound(neighbour, node, graph, state);
        if (cycle_found) {
          return true;
        }
      }
    }
    state[node] = BLACK;
    return false;
  }

  bool allNodesVisited(const std::vector<color>& state) {
    for (int i = 0; i < state.size(); ++i) {
      if (state[i] != BLACK) {
        std::cout << "node " << i << " is " << state[i] << std::endl;
        return false;
      }
    }
    return true;
  }

  bool validTree(int n, vector<vector<int>>& edges) {
    std::vector<std::vector<int>> graph(n, std::vector<int>());
    for (const std::vector<int>& edge : edges) {
      const int source = edge[0];
      const int dest = edge[1];
      graph[source].push_back(dest);
      graph[dest].push_back(source);
    }
    std::vector<color> state(n, WHITE);
    // to check if a graph is a tree:
    // it has no cycles
    // it has only 1 connected component
    return (!dfsCycleFound(0, -1, graph, state)) && allNodesVisited(state);
  }
};
// @lc code=end
