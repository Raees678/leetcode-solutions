/*
 * @lc app=leetcode id=269 lang=cpp
 *
 * [269] Alien Dictionary
 *
 * https://leetcode.com/problems/alien-dictionary/description/
 *
 * algorithms
 * Hard (28.42%)
 * Likes:    1340
 * Dislikes: 258
 * Total Accepted:    114.8K
 * Total Submissions: 338.7K
 * Testcase Example:  '["wrt","wrf","er","ett","rftt"]'
 *
 * There is a new alien language which uses the latin alphabet. However, the
 * order among letters are unknown to you. You receive a list of non-empty
 * words from the dictionary, where words are sorted lexicographically by the
 * rules of this new language. Derive the order of letters in this language.
 *
 * Example 1:
 *
 *
 * Input:
 * [
 * ⁠ "wrt",
 * ⁠ "wrf",
 * ⁠ "er",
 * ⁠ "ett",
 * ⁠ "rftt"
 * ]
 *
 * Output: "wertf"
 *
 *
 * Example 2:
 *
 *
 * Input:
 * [
 * ⁠ "z",
 * ⁠ "x"
 * ]
 *
 * Output: "zx"
 *
 *
 * Example 3:
 *
 *
 * Input:
 * [
 * ⁠ "z",
 * ⁠ "x",
 * ⁠ "z"
 * ]
 *
 * Output: "" 
 *
 * Explanation: The order is invalid, so return "".
 *
 *
 * Note:
 *
 *
 * You may assume all letters are in lowercase.
 * You may assume that if a is a prefix of b, then a must appear before b in
 * the given dictionary.
 * If the order is invalid, return an empty string.
 * There may be multiple valid order of letters, return any one of them is
 * fine.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  bool topologicalSort(std::unordered_map<char, std::set<char>>& graph,
                       std::unordered_set<char>& visiting_nodes,
                       std::unordered_set<char>& visited_nodes, char node,
                       std::string& sorted_string) {
    // we have returned to anode that we have not yet finished visiting
    if (visiting_nodes.find(node) != visiting_nodes.end()) {
      return false;
    }

    visiting_nodes.insert(node);
    bool possible = true;
    for (const char& neighbour : graph[node]) {
      possible = topologicalSort(graph, visiting_nodes, visited_nodes,
                                 neighbour, sorted_string);

      if (!possible) {
        return false;
      }
    }
    visiting_nodes.erase(node);
    if (visited_nodes.find(node) == visited_nodes.end()) {
      visited_nodes.insert(node);
      sorted_string = node + sorted_string;
    }
    return true;
  }

  void buildGraph(std::unordered_map<char, std::set<char>>& graph,
                  std::unordered_set<char>& nodes, vector<string>& words) {
    for (int i = 0; i < words.size(); ++i) {
      for (int j = 0; j < words[i].size(); ++j) {
        nodes.insert(words[i][j]);
      }
    }

    for (int i = 0; i < words.size() - 1; ++i) {
      const string& word_1 = words[i];
      const string& word_2 = words[i + 1];
      int index = 0;
      bool mismatched = false;
      while (index < word_1.size() && index < word_2.size() && !mismatched) {
        if (word_1[index] == word_2[index]) {
          ++index;
        } else {
          mismatched = true;
        }
      }

      if (mismatched) {
        graph[word_1[index]].insert(word_2[index]);
      }
    }
  }

  std::string alienOrder(vector<string>& words) {
    std::unordered_map<char, std::set<char>> graph;
    std::unordered_set<char> nodes;
    // to build a graph we know that each word will be less than the next word
    // compare 2 consecutive words in order
    // for each 2 words compared find the first mismatching character and add an
    // edge
    buildGraph(graph, nodes, words);

    // now our graph is built, do a topologicalSort to get the order of
    // dependencies
    std::unordered_set<char> visiting_nodes;
    std::unordered_set<char> visited_nodes;
    std::string sorted_string = "";
    bool possible = true;
    for (const char& c : nodes) {
      if (visited_nodes.find(c) == visited_nodes.end()) {
        possible = topologicalSort(graph, visiting_nodes, visited_nodes, c,
                                   sorted_string);
      }
      if (!possible) {
        break;
      }
    }

    if (!possible) {
      return "";
    }
    return sorted_string;
  }
};
// @lc code=end
