class Solution {
 public:
  std::string create_string(int low, int high) {
    if (low == high) {
      return to_string(low);
    } else {
      return to_string(low) + "->" + to_string(high);
    }
  }

  vector<string> summaryRanges(vector<int>& nums) {
    std::vector<std::string> result_string;
    if (!nums.size()) {
      return result_string;
    }

    int current_low = nums[0];
    int current_high = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] - 1 == nums[i - 1]) {
        current_high = nums[i];
      } else {
        result_string.push_back(create_string(current_low, current_high));
        current_low = nums[i];
        current_high = nums[i];
      }
    }
    result_string.push_back(create_string(current_low, current_high));
    return result_string;
  }
};