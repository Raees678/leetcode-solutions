class Solution {
 public:
  static inline bool comparator(std::pair<int, bool> point_1,
                                std::pair<int, bool> point_2) {
    if (point_1.first == point_2.first) {
      // std::cout << "points are equal, returning " << point_1.second
      //           << std::endl;
      return point_1.second;
    }
    // std::cout << "points are unequal, returning "
    //           << (point_1.first < point_2.first) << std::endl;
    return point_1.first <= point_2.first;
  }

  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    std::vector<std::vector<int>> result;
    std::vector<std::pair<int, bool>> points;
    for (int i = 0; i < intervals.size(); ++i) {
      points.push_back(std::make_pair(intervals[i][0], true));
      points.push_back(std::make_pair(intervals[i][1], false));
    }

    std::sort(points.begin(), points.end(), comparator);

    int open_intervals = 0;
    int first_open = -1;
    int last_close = -1;
    for (int i = 0; i < points.size(); ++i) {
      if (points[i].second) {
        if (!open_intervals) {
          first_open = points[i].first;
        }
        ++open_intervals;
      } else {
        --open_intervals;
        if (!open_intervals) {
          last_close = points[i].first;
        }
      }
      if (!open_intervals) {
        result.push_back(std::vector<int>{first_open, last_close});
      }
    }

    return result;
  }
};