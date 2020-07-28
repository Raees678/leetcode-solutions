/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 *
 * https://leetcode.com/problems/reconstruct-itinerary/description/
 *
 * algorithms
 * Medium (30.06%)
 * Likes:    1221
 * Dislikes: 780
 * Total Accepted:    116.5K
 * Total Submissions: 344.2K
 * Testcase Example: '[["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]'
 *
 * Given a list of airline tickets represented by pairs of departure and
 * arrival airports [from, to], reconstruct the itinerary in order. All of the
 * tickets belong to a man who departs from JFK. Thus, the itinerary must begin
 * with JFK.
 *
 * Note:
 *
 *
 * If there are multiple valid itineraries, you should return the itinerary
 * that has the smallest lexical order when read as a single string. For
 * example, the itinerary ["JFK", "LGA"] has a smaller lexical order than
 * ["JFK", "LGB"].
 * All airports are represented by three capital letters (IATA code).
 * You may assume all tickets form at least one valid itinerary.
 *
 *
 * Example 1:
 *
 *
 * Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
 * Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
 *
 *
 * Example 2:
 *
 *
 * Input:
 * [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
 * Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
 * Explanation: Another possible reconstruction is
 * ["JFK","SFO","ATL","JFK","ATL","SFO"].
 * But it is larger in lexical order.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  void buildGraph(
      std::unordered_map<std::string, std::map<std::string, int>>& graph,
      std::vector<std::vector<string>>& tickets) {
    for (const std::vector<std::string>& ticket : tickets) {
      std::string source = ticket[0];
      std::string destination = ticket[1];
      graph[source][destination] += 1;
    }
  }

  bool dfs(std::unordered_map<std::string, std::map<std::string, int>>& graph,
           std::vector<std::string>& path, std::string node, int index) {
    path[index] = node;
    if (index == path.size() - 1) {
      return true;
    }

    bool path_filled = false;
    for (std::pair<const std::string, int>& neighbour : graph[node]) {
      if (neighbour.second > 0) {
        --neighbour.second;
        path_filled = dfs(graph, path, neighbour.first, index + 1);
        if (path_filled) {
          break;
        }
        ++neighbour.second;
      }
    }
    return path_filled;
  }

  std::vector<std::string> findItinerary(
      std::vector<std::vector<std::string>>& tickets) {
    std::unordered_map<std::string, std::map<std::string, int>> graph;
    buildGraph(graph, tickets);
    std::vector<std::string> path(tickets.size() + 1);
    bool val = dfs(graph, path, "JFK", 0);
    return path;
  }
};
// @lc code=end
