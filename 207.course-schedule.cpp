/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (35.31%)
 * Likes:    2815
 * Dislikes: 144
 * Total Accepted:    319.5K
 * Total Submissions: 784.2K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 *
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 *
 * Given the total number of courses and a list of prerequisite pairs, is it
 * possible for you to finish all courses?
 *
 * Example 1:
 *
 *
 * Input: 2, [[1,0]]
 * Output: true
 * Explanation: There are a total of 2 courses to take.
 * To take course 1 you should have finished course 0. So it is possible.
 *
 * Example 2:
 *
 *
 * Input: 2, [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take.
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should
 * also have finished course 1. So it is impossible.
 *
 *
 * Note:
 *
 *
 * The input prerequisites is a graph represented by a list of edges, not
 * adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input
 * prerequisites.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  void buildGraph(std::unordered_map<int, std::set<int>>& graph,
                  const vector<vector<int>>& prerequisites) {
    for (int i = 0; i < prerequisites.size(); ++i) {
      graph[prerequisites[i][1]].insert(prerequisites[i][0]);
    }
  }

  bool dfs(std::unordered_map<int, std::set<int>>& graph,
           std::vector<bool>& visiting_nodes, std::vector<bool>& visited_nodes,
           int node) {
    visiting_nodes[node] = true;
    for (const int& i : graph[node]) {
      if (visiting_nodes[i]) {
        return false;
      }
      if (!visited_nodes[i]) {
        bool possible = dfs(graph, visiting_nodes, visited_nodes, i);
        if (!possible) {
          return false;
        }
      }
    }
    visiting_nodes[node] = false;
    visited_nodes[node] = true;
    return true;
  }

  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    std::unordered_map<int, std::set<int>> graph;
    buildGraph(graph, prerequisites);
    std::vector<bool> visiting_nodes(numCourses, false);
    std::vector<bool> visited_nodes(numCourses, false);
    bool result = true;
    for (int i = 0; i < numCourses; ++i) {
      if (!visited_nodes[i]) {
        result = dfs(graph, visiting_nodes, visited_nodes, i);
        if (!result) {
          return false;
        }
      }
    }
    return result;
  }
};
// @lc code=end
