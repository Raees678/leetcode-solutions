/*
 * [983] Validate Stack Sequences
 *
 * https://leetcode.com/problems/validate-stack-sequences/description/
 *
 * algorithms
 * Medium (53.90%)
 * Total Accepted:    2.8K
 * Total Submissions: 5.3K
 * Testcase Example:  '[1,2,3,4,5]\n[4,5,3,2,1]'
 *
 * Given two sequences pushed and popped with distinct values, return true if
 * and only if this could have been the result of a sequence of push and pop
 * operations on an initially empty stack.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
 * Output: true
 * Explanation: We might do the following sequence:
 * push(1), push(2), push(3), push(4), pop() -> 4,
 * push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
 *
 *
 *
 * Example 2:
 *
 *
 * Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
 * Output: false
 * Explanation: 1 cannot be popped before 2.
 *
 *
 *
 *
 * Note:
 *
 *
 * 0 <= pushed.length == popped.length <= 1000
 * 0 <= pushed[i], popped[i] < 1000
 * pushed is a permutation of popped.
 * pushed and popped have distinct values.
 *
 *
 *
 */
class Solution {
 public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    if (!pushed.size()) {
      return true;
    }

    std::stack<int> stackCheck;
    int pushedIndex = 0;
    int poppedIndex = 0;
    stackCheck.push(pushed[pushedIndex]);
    ++pushedIndex;

    while (pushedIndex < pushed.size() && poppedIndex < popped.size()) {
      if (stackCheck.empty() || stackCheck.top() != popped[poppedIndex]) {
        stackCheck.push(pushed[pushedIndex]);
        ++pushedIndex;
      } else {
        stackCheck.pop();
        ++poppedIndex;
      }
    }

    while (poppedIndex < popped.size()) {
      if (stackCheck.empty() || stackCheck.top() != popped[poppedIndex]) {
        return false;
      } else {
        stackCheck.pop();
        ++poppedIndex;
      }
    }

    return true;
  }
};
