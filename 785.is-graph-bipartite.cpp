/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * [785] Is Graph Bipartite?
 *
 * https://leetcode.com/problems/is-graph-bipartite/description/
 *
 * algorithms
 * Medium (40.32%)
 * Likes:    1008
 * Dislikes: 126
 * Total Accepted:    80.7K
 * Total Submissions: 176.1K
 * Testcase Example:  '[[1,3],[0,2],[1,3],[0,2]]'
 *
 * Given an undirected graph, return true if and only if it is bipartite.
 *
 * Recall that a graph is bipartite if we can split it's set of nodes into two
 * independent subsets A and B such that every edge in the graph has one node
 * in A and another node in B.
 *
 * The graph is given in the following form: graph[i] is a list of indexes j
 * for which the edge between nodes i and j exists.  Each node is an integer
 * between 0 and graph.length - 1.  There are no self edges or parallel edges:
 * graph[i] does not contain i, and it doesn't contain any element twice.
 *
 *
 * Example 1:
 * Input: [[1,3], [0,2], [1,3], [0,2]]
 * Output: true
 * Explanation:
 * The graph looks like this:
 * 0----1
 * |    |
 * |    |
 * 3----2
 * We can divide the vertices into two groups: {0, 2} and {1, 3}.
 *
 *
 *
 * Example 2:
 * Input: [[1,2,3], [0,2], [0,1,3], [0,2]]
 * Output: false
 * Explanation:
 * The graph looks like this:
 * 0----1
 * | \  |
 * |  \ |
 * 3----2
 * We cannot find a way to divide the set of nodes into two independent
 * subsets.
 *
 *
 *
 *
 * Note:
 *
 *
 * graph will have length in range [1, 100].
 * graph[i] will contain integers in range [0, graph.length - 1].
 * graph[i] will not contain i or duplicate values.
 * The graph is undirected: if any element j is in graph[i], then i will be in
 * graph[j].
 *
 *
 */

// @lc code=start
class Solution {
 public:
  enum color { RED, WHITE, GREY, NONE };
  color switchColour(color color) {
    if (color == RED) {
      return WHITE;
    } else if (color == WHITE) {
      return RED;
    }
    // should never reach
    return NONE;
  }

  bool dfsColor(const std::vector<std::vector<int>>& graph,
                std::vector<color>& node_colors, int node, color col) {
    if (node_colors[node] == NONE) {
      node_colors[node] = col;
      for (int i = 0; i < graph[node].size(); ++i) {
        int neighbour = graph[node][i];
        bool possible =
            dfsColor(graph, node_colors, neighbour, switchColour(col));
        if (!possible) {
          return false;
        }
      }
    } else if (node_colors[node] != col) {
      return false;
    }
    return true;
  }

  bool isBipartite(std::vector<std::vector<int>>& graph) {
    std::vector<color> node_colors(graph.size(), NONE);
    bool possible = true;
    for (int i = 0; i < graph.size(); ++i) {
      if (node_colors[i] == NONE) {
        possible = dfsColor(graph, node_colors, i, RED);
      }
      if (!possible) {
        break;
      }
    }
    return possible;
  }
};
// @lc code=end
