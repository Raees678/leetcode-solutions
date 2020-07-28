class Solution {
  std::unordered_map<char, char> bracket_match{{')', '('},  {']', '['},
                                               {'}', '{'},  {'(', '\0'},
                                               {'[', '\0'}, {'{', '\0'}};

 public:
  bool isValid(string s) {
    std::cout << "checking " << std::endl;

    std::stack<char> unmatched_brackets;
    // for each character
    for (const char& c : s) {
      // if the stack is empty we must push, or if the bracket is not matching
      // the last opened bracket we push it to make it the new last opened
      // bracket
      if (unmatched_brackets.empty() ||
          unmatched_brackets.top() != bracket_match[c]) {
        unmatched_brackets.push(c);
        // otherwise if the bracket is matching the last opened bracket we pop
        // the last opened bracket of the stack since it has been matched
      } else if (unmatched_brackets.top() == bracket_match[c]) {
        unmatched_brackets.pop();
        // otherwise oops, we are closing a bracket that cannot be closed yet
        // because there is a different open bracket that is yet unclosed
      } else {
        return false;
      }
    }

    // if we ended up closing all brackets the stack is empty
    if (unmatched_brackets.empty()) {
      return true;
    }
    // otherwise brackets are yet to be closed
    return false;
  }
};