class Solution {
 public:
  int getPalindromeSize(const std::pair<int, int>& palindrome_bounds) {
    return palindrome_bounds.second - palindrome_bounds.first + 1;
  }

  std::pair<int, int> expandOutwardOdd(int center, const std::string& s) {
    int left = center - 1;
    int right = center + 1;
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
      --left;
      ++right;
    }
    return std::make_pair(left + 1, right - 1);
  }

  std::pair<int, int> expandOutwardEven(int center_left, int center_right,
                                        const std::string& s) {
    int left = center_left - 1;
    int right = center_right + 1;
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
      --left;
      ++right;
    }
    return std::make_pair(left + 1, right - 1);
  }

  string longestPalindrome(string s) {
    std::cout << "s: " << s << std::endl;
    std::cout << "size: " << s.size() << std::endl;
    if (!s.size()) {
      std::cout << "here" << std::endl;
      return "";
    }

    std::pair<int, int> best_p({0, 0});
    for (int i = 0; i < s.size(); ++i) {
      std::pair<int, int> current_odd_p = expandOutwardOdd(i, s);
      if (getPalindromeSize(best_p) < getPalindromeSize(current_odd_p)) {
        best_p = current_odd_p;
      }
    }

    for (int i = 0; i < s.size() - 1; ++i) {
      if (s[i] == s[i + 1]) {
        std::pair<int, int> current_even_p = expandOutwardEven(i, i + 1, s);
        if (getPalindromeSize(best_p) < getPalindromeSize(current_even_p)) {
          best_p = current_even_p;
        }
      }
    }

    return s.substr(best_p.first, best_p.second - best_p.first + 1);
  }
};
