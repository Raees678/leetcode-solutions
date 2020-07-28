class MedianFinder {
 public:
  /** initialize your data structure here. */
  std::priority_queue<int> lower_half;
  std::priority_queue<int, std::vector<int>, std::greater<int>> upper_half;

  MedianFinder() : lower_half(), upper_half(std::greater<int>()) {}

  void addNum(int num) {
    if (!(lower_half.size() + upper_half.size())) {
      upper_half.push(num);
      return;
    }
    if (num < upper_half.top()) {
      lower_half.push(num);
    } else {
      upper_half.push(num);
    }
    rebalance();
  }

  void rebalance() {
    if (std::fabs(static_cast<int>(lower_half.size()) -
                  static_cast<int>(upper_half.size())) > 1) {
      if (lower_half.size() > upper_half.size()) {
        int top = lower_half.top();
        lower_half.pop();
        upper_half.push(top);
      } else {
        int top = upper_half.top();
        upper_half.pop();
        lower_half.push(top);
      }
    }
  }

  double findMedian() {
    if (!((lower_half.size() + upper_half.size()) % 2)) {
      return (lower_half.top() + upper_half.top()) / 2.0;
    }
    if (upper_half.size() > lower_half.size()) {
      return upper_half.top();
    }
    return lower_half.top();
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */