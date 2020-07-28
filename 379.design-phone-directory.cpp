/*
 * @lc app=leetcode id=379 lang=cpp
 *
 * [379] Design Phone Directory
 *
 * https://leetcode.com/problems/design-phone-directory/description/
 *
 * algorithms
 * Medium (38.43%)
 * Likes:    131
 * Dislikes: 208
 * Total Accepted:    29.1K
 * Total Submissions: 66K
 * Testcase Example:
 '["PhoneDirectory","get","get","check","get","check","release","check"]\n' +
  '[[3],[],[],[2],[],[2],[2],[2]]'
 *
 * Design a Phone Directory which supports the following operations:
 *
 *
 *
 * get: Provide a number which is not assigned to anyone.
 * check: Check if a number is available or not.
 * release: Recycle or release a number.
 *
 *
 *
 * Example:
 *
 * // Init a phone directory containing a total of 3 numbers: 0, 1, and 2.
 * PhoneDirectory directory = new PhoneDirectory(3);
 *
 * // It can return any available phone number. Here we assume it returns 0.
 * directory.get();
 *
 * // Assume it returns 1.
 * directory.get();
 *
 * // The number 2 is available, so return true.
 * directory.check(2);
 *
 * // It returns 2, the only number that is left.
 * directory.get();
 *
 * // The number 2 is no longer available, so return false.
 * directory.check(2);
 *
 * // Release number 2 back to the pool.
 * directory.release(2);
 *
 * // Number 2 is available again, return true.
 * directory.check(2);
 *
 *
 */
#include <vector>
// @lc code=start
class PhoneDirectory {
 public:
  /** Initialize your data structure here
      @param maxNumbers - The maximum numbers that can be stored in the phone
     directory. */
  std::vector<int> numbers;
  PhoneDirectory(int maxNumbers) : numbers(maxNumbers){};

  /** Provide a number which is not assigned to anyone.
      @return - Return an available number. Return -1 if none is available. */
  int get() {
    for (int i = 0; i < numbers.size(); ++i) {
      if (!numbers[i]) {
        numbers[i] = 1;
        return i;
      }
    }
    return -1;
  }

  /** Check if a number is available or not. */
  bool check(int number) {
    // ALWAYS DO BOUNDS CHECKING ON THIS
    if (number < 0 || number >= vector.size()) {
      return false;
    }
    return !numbers[number];
  }

  /** Recycle or release a number. */

  void release(int number) {
    if (number >= 0 && number < vector.size()) {
      numbers[number] = 0;
    }
  }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */
// @lc code=end
