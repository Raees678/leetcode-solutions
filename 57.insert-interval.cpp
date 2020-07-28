class Solution {
 public:
  inline void mergeIntervals(std::vector<int>& int_1,
                             const std::vector<int>& int_2) {
    int_1[0] = std::min(int_1[0], int_2[0]);
    int_1[1] = std::max(int_1[1], int_2[1]);
  }

  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& new_interval) {
    std::vector<std::vector<int>> results;
    int index = 0;
    while (index < intervals.size()) {
      if (intervals[index][0] < new_interval[0]) {
        results.push_back(intervals[index]);
      } else {
        break;
      }
      ++index;
    }

    if (!results.size() || results.back()[1] < new_interval[0]) {
      results.push_back(new_interval);
    } else {
      // merge back() and new_interval
      mergeIntervals(results.back(), new_interval);
    }

    while (index < intervals.size()) {
      if (intervals[index][1] > results.back()[1]) {
        if (intervals[index][0] <= results.back()[1]) {
          // merge back() and intervals[index]
          mergeIntervals(results.back(), intervals[index]);
        } else {
          results.push_back(intervals[index]);
        }
      }
      ++index;
    }

    return results;
  }
};