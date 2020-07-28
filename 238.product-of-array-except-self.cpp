class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    std::vector<int> pre_product(nums.size());
    std::vector<int> post_product(nums.size());
    std::vector<int> result(nums.size());
    pre_product[0] = 1;
    post_product[nums.size() - 1] = 1;

    int running_product = 1;
    for (int i = 0; i < nums.size() - 1; ++i) {
      running_product *= nums[i];
      pre_product[i + 1] = running_product;
    }

    running_product = 1;
    for (int i = nums.size() - 1; i > 0; --i) {
      running_product *= nums[i];
      post_product[i - 1] = running_product;
    }

    for (int i = 0; i < result.size(); ++i) {
      result[i] = pre_product[i] * post_product[i];
    }
    return result;
  }
};