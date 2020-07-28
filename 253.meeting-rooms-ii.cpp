class Solution {
 public:
  static bool comparator(std::pair<int, bool> point_1,
                         std::pair<int, bool> point_2) {
    if (point_1.first == point_2.first) {
      // if two points are equal then if the first point is an endpoint please
      // return that one first
      return !point_1.second;
    }
    return point_1.first < point_2.first;
  }

  int minMeetingRooms(vector<vector<int>>& intervals) {
    std::vector<std::pair<int, bool>> points;
    for (int i = 0; i < intervals.size(); ++i) {
      std::vector<int>& interval = intervals[i];
      int start_point = interval[0];
      int end_point = interval[1];
      points.push_back(std::make_pair(start_point, true));
      points.push_back(std::make_pair(end_point, false));
    }

    std::sort(points.begin(), points.end(), comparator);
    int overlappint_intervals = 0;
    int max_overlappint_intervals = 0;
    for (int i = 0; i < points.size(); ++i) {
      if (points[i].second) {
        ++overlappint_intervals;
        max_overlappint_intervals =
            std::max(overlappint_intervals, max_overlappint_intervals);
      } else {
        --overlappint_intervals;
      }
    }

    return max_overlappint_intervals;
  }
};