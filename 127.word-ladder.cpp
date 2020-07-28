/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 *
 * https://leetcode.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (21.59%)
 * Likes:    2292
 * Dislikes: 979
 * Total Accepted:    348.6K
 * Total Submissions: 1.3M
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * Given two words (begin_word and end_word), and a dictionary's word list, find
 * the length of shortest transformation sequence from begin_word to end_word,
 * such that:
 *
 *
 * Only one letter can be changed at a time.
 * Each transformed word must exist in the word list. Note that begin_word is
 * not a transformed word.
 *
 *
 * Note:
 *
 *
 * Return 0 if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume begin_word and end_word are non-empty and are not the same.
 *
 *
 * Example 1:
 *
 *
 * Input:
 * begin_word = "hit",
 * end_word = "cog",
 * word_list = ["hot","dot","dog","lot","log","cog"]
 *
 * Output: 5
 *
 * Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" ->
 * "dog" -> "cog",
 * return its length 5.
 *
 *
 * Example 2:
 *
 *
 * Input:
 * begin_word = "hit"
 * end_word = "cog"
 * word_list = ["hot","dot","dog","lot","log"]
 *
 * Output: 0
 *
 * Explanation: The end_word "cog" is not in word_list, therefore no possible
 * transformation.
 *
 *
 *
 *
 *
 */

// @lc code=start
class Solution {
 public:
  std::vector<std::string> getGenericWords(std::string word) {
    std::vector<std::string> generic_words;
    for (int i = 0; i < word.size(); ++i) {
      std::string generic_word = word.substr(0, i) + "*";
      if (i + 1 < word.size()) {
        generic_word += word.substr(i + 1);
      }
      generic_words.push_back(generic_word);
    }
    return generic_words;
  }

  int ladderLength(string begin_word, string end_word,
                   vector<string>& word_list) {
    // first we need to construct the word_list into a graph
    // we construct a map that holds an intermediate representation of each word
    std::unordered_map<std::string, std::vector<std::string>> word_graph;
    // for each word, edit each character to a generic *
    for (std::string word : word_list) {
      std::vector<std::string> generic_words = getGenericWords(word);
      for (std::string generic_word : generic_words) {
        word_graph[generic_word].push_back(word);
      }
    }

    // average complexity so far: O(length*n)
    // worst case complexity so far: O(length*n^2)
    std::unordered_set<std::string> visited_words;
    std::queue<std::pair<std::string, int>> queued_words;
    queued_words.push(std::make_pair(begin_word, 1));

    while (!queued_words.empty()) {
      std::pair<std::string, int> current_node = queued_words.front();
      queued_words.pop();
      std::string& current_word = current_node.first;
      visited_words.insert(current_word);
      int& current_distance = current_node.second;
      // if the current word is the end word then return the current distance
      if (current_word == end_word) {
        return current_distance;
      }
      // push back all words that are 1 character apart from the current_word
      std::vector<std::string> generic_words = getGenericWords(current_word);
      for (std::string& generic_word : generic_words) {
        for (std::string& word : word_graph[generic_word]) {
          if (visited_words.find(word) == visited_words.end()) {
            queued_words.push(std::make_pair(word, current_distance + 1));
          }
        }
      }
    }
    // average case complexity so far: O(length*n) + O(n) = O(length*n)
    // worst case complexity so far: O(length*n^2) + O(n^2) = O(length*n^2)
    // no words found, return 0
    return 0;
  }
};
// @lc code=end
