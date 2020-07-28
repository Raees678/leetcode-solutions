/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 *
 * https://leetcode.com/problems/course-schedule-ii/description/
 *
 * algorithms
 * Medium (32.19%)
 * Likes:    1538
 * Dislikes: 103
 * Total Accepted:    207.9K
 * Total Submissions: 549K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 *
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 *
 * Given the total number of courses and a list of prerequisite pairs, return
 * the ordering of courses you should take to finish all courses.
 *
 * There may be multiple correct orders, you just need to return one of them.
 * If it is impossible to finish all courses, return an empty array.
 *
 * Example 1:
 *
 *
 * Input: 2, [[1,0]]
 * Output: [0,1]
 * Explanation: There are a total of 2 courses to take. To take course 1 you
 * should have finished
 * course 0. So the correct course order is [0,1] .
 *
 * Example 2:
 *
 *
 * Input: 4, [[1,0],[2,0],[3,1],[3,2]]
 * Output: [0,1,2,3] or [0,2,1,3]
 * Explanation: There are a total of 4 courses to take. To take course 3 you
 * should have finished both
 * ⁠            courses 1 and 2. Both courses 1 and 2 should be taken after
 * you finished course 0. So one correct course order is [0,1,2,3]. Another
 * correct ordering is [0,2,1,3] .
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
  bool topologicalSort(int node,
                       std::unordered_map<int, std::vector<int>>& graph,
                       std::unordered_set<int>& visiting_nodes,
                       std::unordered_set<int>& visited_nodes,
                       std::vector<int>& sorted_nodes) {
    visiting_nodes.insert(node);
    for (int neighbour : graph[node]) {
      // we found a neighbour that has been previously visiting but not fully
      // visited. a back edge exists so return false
      if (visiting_nodes.find(neighbour) != visiting_nodes.end()) {
        return false;
      }
      // otherwise
      bool result = topologicalSort(neighbour, graph, visiting_nodes,
                                    visited_nodes, sorted_nodes);
      if (!result) {
        // if topological sort on a neighbour results in a back edge being found
        // then stop and just return
        return result;
      }
    }
    // node visiting has completed and all its neighbours have been explored
    visiting_nodes.erase(node);
    // node is now visited
    if (visited_nodes.find(node) == visited_nodes.end()) {
      sorted_nodes.push_back(node);
      visited_nodes.insert(node);
    }
    return true;
  }

  vector<int> findOrder(int num_courses, vector<vector<int>>& prerequisites) {
    std::unordered_map<int, std::vector<int>> graph;
    for (vector<int>& course_and_preq : prerequisites) {
      // graph keys are prerequisites
      // graph values are courses that they unlock
      graph[course_and_preq[1]].push_back(course_and_preq[0]);
    }

    std::unordered_set<int> visiting_nodes;
    std::unordered_set<int> visited_nodes;
    vector<int> sorted_nodes;
    bool possible = true;
    for (int i = 0; i < num_courses && possible; ++i) {
      // only do topsort DFS on unvisited nodes
      if (visited_nodes.find(i) == visited_nodes.end()) {
        possible = topologicalSort(i, graph, visiting_nodes, visited_nodes,
                                   sorted_nodes);
      }
    }

    if (possible) {
      std::vector<int> reverse_sort;
      for (std::vector<int>::reverse_iterator it = sorted_nodes.rbegin();
           it != sorted_nodes.rend(); ++it) {
        reverse_sort.push_back(*it);
      }
      return reverse_sort;
    }
    return std::vector<int>();
  }
};
// @lc code=end
