class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    std::unordered_set<int> seen_elems;
    for (int i = 0; i < nums.size(); ++i) {
      seen_elems.insert(nums[i]);
    }
    int max_count = 0;
    for (int i = 0; i < nums.size(); ++i) {
      int elem = nums[i];
      if (seen_elems.find(elem - 1) != seen_elems.end()) {
        continue;
      }
      int count = 1;
      while (seen_elems.find(++elem) != seen_elems.end()) {
        ++count;
      }
      max_count = std::max(max_count, count);
    }
    return max_count;
  }
};