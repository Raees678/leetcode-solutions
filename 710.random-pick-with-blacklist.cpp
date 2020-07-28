/*
 * [894] Random Pick with Blacklist
 *
 * https://leetcode.com/problems/random-pick-with-blacklist/description/
 *
 * algorithms
 * Hard (29.74%)
 * Total Accepted:    2.9K
 * Total Submissions: 9.7K
 * Testcase Example:  '["Solution", "pick", "pick", "pick"]\n[[1, []], [], [],
 * []]'
 *
 * Given a blacklist B containing unique integers from [0, N), write a function
 * to return a uniform random integer from [0, N) which is NOT in B.
 *
 * Optimize it such that it minimizes the call to system’s Math.random().
 *
 * Note:
 *
 *
 * 1 <= N <= 1000000000
 * 0 <= B.length < min(100000, N)
 * [0, N) does NOT include N. See interval notation.
 *
 *
 * Example 1:
 *
 *
 * Input:
 * ["Solution","pick","pick","pick"]
 * [[1,[]],[],[],[]]
 * Output: [null,0,0,0]
 *
 *
 * Example 2:
 *
 *
 * Input:
 * ["Solution","pick","pick","pick"]
 * [[2,[]],[],[],[]]
 * Output: [null,1,1,1]
 *
 *
 * Example 3:
 *
 *
 * Input:
 * ["Solution","pick","pick","pick"]
 * [[3,[1]],[],[],[]]
 * Output: [null,0,0,2]
 *
 *
 * Example 4:
 *
 *
 * Input:
 * ["Solution","pick","pick","pick"]
 * [[4,[2]],[],[],[]]
 * Output: [null,1,3,1]
 *
 *
 * Explanation of Input Syntax:
 *
 * The input is two lists: the subroutines called and their arguments.
 * Solution's constructor has two arguments, N and the blacklist B. pick has no
 * arguments. Arguments are always wrapped with a list, even if there aren't
 * any.
 *
 */
class Solution {
  int N_;
  vector<int> blacklist_;

 public:
  Solution(int N, vector<int> blacklist) {
    N_ = N;
    std::sort(blacklist.begin(), blacklist.end());
    blacklist_ = blacklist;
  }

  int pick() {
    // pick a random index k from the size of the whitelist
    // we want to find the index of the blacklist number just below
    // whitelist_[k]
    int k = rand() % (N_ - blacklist_.size());

    if (blacklist_.size() == 0) {
      return k;
    }

    int low = 0;
    int high = blacklist_.size();

    // blacklist_[middle] - middle is the number of whitelist numbers less
    // than blacklist_[middle]
    // binary search to find the largest blacklist number that has <= k
    // whitelist numbers before it
    // this is the largest blacklist number before whitelist[k]

    while (low < high) {
      int middle = (low + high) / 2;
      // blacklist_[middle] - middle is the number of whitelist numbers less
      // than blacklist_[k]
      if (blacklist_[middle] - middle > k) {
        high = middle;
      } else {
        low = middle + 1;
      }
    }
    // at this point low-1 is the index of the largest blacklist number
    // smaller than whitelist[k]
    // this index MAY be out of bounds i.e. negative if there is no blacklist
    // number smaller than whitelist[k]

    // if index is negative
    // there is no blacklist number smaller than whitelist[k]
    // so whitelist[k] is k itself since there is nothing in the blacklist that
    // could possibly cause its value to go up (all whitelist numbers are unique
    // and whitelist[k] is at least k])
    if (low - 1 < 0) {
      return k;
    } else {
      // low - 1 is the blacklsit index of the largest number smaller than
      // whitelist[k]
      // the blacklist has low numbers that appear before whitelist[k] (since
      // indexing starts at 0)
      // so the whitelist[k] MUST BE low + k
      return low + k;
    }
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(N, blacklist);
 * int param_1 = obj.pick();
 */
