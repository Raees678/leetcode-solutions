class Solution {
 public:
  struct Compare {
    inline static int distance(const std::vector<int>& point) {
      return point[0] * point[0] + point[1] * point[1];
    }

    bool operator()(const std::vector<int>& point_1,
                    const std::vector<int>& point_2) {
      return distance(point_1) < distance(point_2);
    }
  };

  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    // lets mantain a max heap of size k
    // use a priority queue as the heap
    if (k == points.size()) {
      return points;
    }
    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>,
                        Compare>
        queue;

    for (int i = 0; i < points.size(); ++i) {
      queue.push(points[i]);
      if (queue.size() > k) {
        queue.pop();
      }
    }

    std::vector<std::vector<int>> result;
    for (int i = 0; i < k; ++i) {
      result.push_back(queue.top());
      queue.pop();
    }
    return result;
  }
};