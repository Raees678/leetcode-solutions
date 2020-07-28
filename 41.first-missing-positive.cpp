class Solution {
 public:
  int firstMissingPositive(vector<int>& nums) {
    int one_found = false;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == 1) {
        one_found = true;
        break;
      }
    }

    if (!one_found) {
      return 1;
    }

    // 1 is in the input
    // map non positive numbers to 1 so as to free up numbers for the markers
    // space

    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] <= 0) {
        nums[i] = 1;
      }
    }

    for (int i = 0; i < nums.size(); ++i) {
      // convert the input to an index and try to reach it
      int input = nums[i] - 1;
      while (input >= 0 && input < nums.size() - 1) {
        int leads_to_input = nums[input] - 1;
        nums[input] = -1;
        input = leads_to_input;
      }
    }

    for (int i = 0; i < nums.size(); ++i) {
      // if input is not -1, no previous input in the array has led here
      // so this index is basically never reached
      // return the first instance of this since we are attempting to reach all
      // the indices in the array and trying to find the first non reached index
      // from the input
      // the output is always 1 + the index since the solution space is 1 ... n
      // + 1
      if (nums[i] != -1) {
        return i + 1;
      }
    }

    // all indices can be reached from the array
    // the first index that wouldnt be reached is the past the end index
    return nums.size() + 1;
  }
};