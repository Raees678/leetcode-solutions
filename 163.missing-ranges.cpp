class Solution {
 public:
  // adds to results a rnage inclusive of lower and upper
  void addToResults(int lower, int upper, vector<string>& results) {
    if (lower == upper) {
      results.push_back(to_string(lower));
    } else {
      results.push_back(to_string(lower) + "->" + to_string(upper));
    }
    return;
  }

  // gets range exclusive of low and high
  void getRange(int low, bool low_inclusive, int high, bool high_inclusive,
                vector<string>& results) {
    // wea are trying to convert a potentially exclusive range to an inclusive
    // range. if any of the numbers lie on the boundary of the exclusive range
    // they cant become ranges anyway
    if ((!low_inclusive && low == INT_MAX) ||
        (!high_inclusive && high == INT_MIN)) {
      return;
    }
    if (!low_inclusive) {
      ++low;
    }

    if (!high_inclusive) {
      --high;
    }

    // verify that the range is actualy a valid range
    if (low > high) {
      return;
    }
    addToResults(low, high, results);
    return;
  }

  vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
    std::vector<std::string> results;
    if (!nums.size()) {
      addToResults(lower, upper, results);
      return results;
    }

    // get range from lower to first element in nums
    getRange(lower, true, nums[0], false, results);
    for (int i = 0; i < nums.size() - 1; ++i) {
      // for each unique pair of numbers in nums get a range for numbers between
      // them
      int first = nums[i];
      int second = nums[i + 1];
      getRange(first, false, second, false, results);
    }
    // get range from last element in nums to upper
    getRange(nums[nums.size() - 1], false, upper, true, results);
    return results;
  }
};