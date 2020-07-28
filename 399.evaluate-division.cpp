/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 *
 * https://leetcode.com/problems/evaluate-division/description/
 *
 * algorithms
 * Medium (44.32%)
 * Likes:    1826
 * Dislikes: 140
 * Total Accepted:    108.7K
 * Total Submissions: 217.9K
 * Testcase Example:  '[["a","b"],["b","c"]]\n' +
  '[2.0,3.0]\n' +
  '[["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]'
 *
 * Equations are given in the format A / B = k, where A and B are variables
 * represented as strings, and k is a real number (floating point number).
 * Given some queries, return the answers. If the answer does not exist, return
 * -1.0.
 *
 * Example:
 * Given  a / b = 2.0, b / c = 3.0.
 * queries are:  a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
 * return  [6.0, 0.5, -1.0, 1.0, -1.0 ].
 *
 * The input is:  vector<pair<string, string>> equations, vector<double>&
 * values, vector<pair<string, string>> queries , where equations.size() ==
 * values.size(), and the values are positive. This represents the equations.
 * Return  vector<double>.
 *
 * According to the example above:
 *
 *
 * equations = [ ["a", "b"], ["b", "c"] ],
 * values = [2.0, 3.0],
 * queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"]
 * ].
 *
 *
 *
 * The input is always valid. You may assume that evaluating the queries will
 * result in no division by zero and there is no contradiction.
 *
 */

// @lc code=start
class Solution {
 public:
  double dfs(std::unordered_map<std::string,
                                std::unordered_map<std::string, double>>& graph,
             std::string current_node, const std::string& target_node,
             std::set<std::string> visiting_nodes,
             std::set<std::string> visited_nodes) {
    if (current_node == target_node) {
      if (graph.find(current_node) != graph.end()) {
        return 1;
      }
      return -1;
    }

    visiting_nodes.insert(current_node);
    for (std::pair<const std::string, double>& neighbour :
         graph[current_node]) {
      if (visiting_nodes.find(neighbour.first) == visiting_nodes.end() &&
          visited_nodes.find(neighbour.first) == visited_nodes.end()) {
        double possible_weight = dfs(graph, neighbour.first, target_node,
                                     visiting_nodes, visited_nodes);
        if (possible_weight != -1) {
          return neighbour.second * possible_weight;
        }
      }
    }

    visiting_nodes.erase(current_node);
    visited_nodes.insert(current_node);
    return -1;
  }
  vector<double> calcEquation(vector<vector<string>>& equations,
                              vector<double>& values,
                              vector<vector<string>>& queries) {
    std::unordered_map<std::string, std::unordered_map<std::string, double>>
        graph;
    for (int i = 0; i < equations.size(); ++i) {
      std::string first = equations[i][0];
      std::string second = equations[i][1];
      graph[second].insert(std::make_pair(first, 1 / values[i]));
      graph[first].insert(std::make_pair(second, values[i]));
    }

    // the graph now contains the weights of x/y as an edge x->y
    // do a dfs to find possible paths between queries and multiply the edge
    // weights as you go along
    // if no paths found return -1
    std::vector<double> results;
    for (int i = 0; i < queries.size(); ++i) {
      std::set<std::string> visiting_nodes;
      std::set<std::string> visited_nodes;
      double result = dfs(graph, queries[i][0], queries[i][1], visiting_nodes,
                          visited_nodes);
      results.push_back(result);
    }

    return results;
  }
};
// @lc code=end
