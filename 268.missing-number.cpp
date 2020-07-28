class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
      int input = nums[i];
      while (input >= 0 && input < nums.size()) {
        int followed_input = nums[input];
        nums[input] = -1;
        followed_input = input;
      }
    }

    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != -1) {
        return i;
      }
    }
    return -1;
  }
};