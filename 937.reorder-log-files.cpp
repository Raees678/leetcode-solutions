/*
 * [974] Reorder Log Files
 *
 * https://leetcode.com/problems/reorder-log-files/description/
 *
 * algorithms
 * Easy (54.88%)
 * Total Accepted:    2.9K
 * Total Submissions: 5.2K
 * Testcase Example:  '["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key
 * dog","a8 act zoo"]'
 *
 * You have an array of logs.  Each log is a space delimited string of words.
 *
 * For each log, the first word in each log is an alphanumeric identifier.
 * Then, either:
 *
 *
 * Each word after the identifier will consist only of lowercase letters,
 * or;
 * Each word after the identifier will consist only of digits.
 *
 *
 * We will call these two varieties of logs letter-logs and digit-logs.  It is
 * guaranteed that each log has at least one word after its identifier.
 *
 * Reorder the logs so that all of the letter-logs come before any digit-log.
 * The letter-logs are ordered lexicographically ignoring identifier, with the
 * identifier used in case of ties.  The digit-logs should be put in their
 * original order.
 *
 * Return the final order of the logs.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
 * Output: ["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4
 * 7"]
 *
 *
 *
 *
 * Note:
 *
 *
 * 0 <= logs.length <= 100
 * 3 <= logs[i].length <= 100
 * logs[i] is guaranteed to have an identifier, and a word after the
 * identifier.
 *
 *
 */
class Solution {
  static bool comp(const string& first, const string& second) {
    bool firstNum = false;
    bool secondNum = false;
    string firstWord = first.substr(first.find_first_of(' '));
    // std::cout << "comparing " << first << " with " << second << std::endl;
    string secondWord = second.substr(second.find_first_of(' '));

    if ('0' <= firstWord[1] && firstWord[1] <= '9') {
      firstNum = true;
    }

    if ('0' <= secondWord[1] && secondWord[1] <= '9') {
      secondNum = true;
    }

    if (firstNum && secondNum) {
      // std::cout << "less" << std::endl;
      return false;
    }

    if (firstNum && !secondNum) {
      // std::cout << "more" << std::endl;
      return false;
    }

    if (!firstNum && secondNum) {
      // std::cout << "less" << std::endl;
      return true;
    }

    if (!firstNum && !secondNum) {
      if (firstWord == secondWord) {
        if (first < second) {
          // std::cout << "less" << std::endl;
        } else {
          // std::cout << "more" << std::endl;
        }
        return first < second;
      } else {
        if (firstWord < secondWord) {
          // std::cout << "less" << std::endl;
        } else {
          // std::cout << "more" << std::endl;
        }
        return firstWord < secondWord;
      }
    }
  }

 public:
  vector<string> reorderLogFiles(vector<string>& logs) {
    std::stable_sort(logs.begin(), logs.end(), comp);
    return logs;
  }
};
