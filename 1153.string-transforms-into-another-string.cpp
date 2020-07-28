// Given two strings str1 and str2 of the same length, determine whether you can
// transform str1 into str2 by doing zero or more conversions.
//
// In one conversion you can convert all occurrences of one character in str1 to
// any other lowercase English character.
//
// Return true if and only if you can transform str1 into str2.
//
//
//
// --------------------------------------------------
//
// Example 1:
//
//
// Input: str1 = "aabcc", str2 = "ccdee"
// Output: true
// Explanation: Convert 'c' to 'e' then 'b' to 'd' then 'a' to 'c'. Note that
// the order of conversions matter.
//
//
// --------------------------------------------------
//
// Example 2:
//
//
// Input: str1 = "leetcode", str2 = "codeleet"
// Output: false
// Explanation: There is no way to transform str1 to str2.
//
//
//
//
// * * * * * * * * * * * * * * * * * * * * * * * * *
//
// Note:
//
//
// 	1 <= str1.length == str2.length <= 10^4
// 	Both str1 and str2 contain only lowercase English letters.
//
//
class Solution {
 public:
  bool canConvert(string str1, string str2) {
    if (str1 == str2) {
      return true;
    }
    std::vector<char> graph(26, '\0');
    std::vector<int> indegree(26, 0);

    for (int i = 0; i < str1.size(); ++i) {
      char source = str1[i];
      char dest = str2[i];
      if (graph[source - 'a'] == '\0' || graph[source - 'a'] == dest) {
        // std::cout << "setting " << source << " to " << dest << std::endl;
        graph[source - 'a'] = dest;
      } else {
        // each letter can only be mapped to another one letter
        // its a many to one relationship between letters in the graph
        // if a single letter
        // std::cout << source << " has previous map to " << graph[source]
        //           << std::endl;
        return false;
      }
      ++indegree[dest - 'a'];
    }

    int zero_indegree_nodes = 0;
    int excess_indegree_edges = 0;
    for (int i = 0; i < 26; ++i) {
      if (!indegree[i]) {
        ++zero_indegree_nodes;
      } else if (indegree[i] > 1) {
        excess_indegree_edges += indegree[i] - 1;
      }
    }

    // are there any nodes with no incoming edges that we can use as spare
    if (zero_indegree_nodes && excess_indegree_edges <= zero_indegree_nodes) {
      return true;
    }
    return false;
  }
};