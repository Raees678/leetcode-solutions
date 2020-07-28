class Solution {
 public:
  inline void increment_col(std::vector<std::vector<int>>& matrix,
                            int& current_row, int& current_col, int& low_row,
                            int& high_row, int& low_col, int& high_col,
                            std::vector<int>& results, bool& possible) {
    if (current_col > high_col) {
      possible = false;
      return;
    }

    while (current_col <= high_col) {
      results.push_back(matrix[current_row][current_col]);
      ++current_col;
    }
    --current_col;
    ++current_row;
    low_row = current_row;
    return;
  }

  inline void increment_row(std::vector<std::vector<int>>& matrix,
                            int& current_row, int& current_col, int& low_row,
                            int& high_row, int& low_col, int& high_col,
                            std::vector<int>& results, bool& possible) {
    if (current_row > high_row) {
      possible = false;
      return;
    }

    while (current_row <= high_row) {
      results.push_back(matrix[current_row][current_col]);
      ++current_row;
    }
    --current_row;
    --current_col;
    high_col = current_col;
    return;
  }

  inline void decrement_col(std::vector<std::vector<int>>& matrix,
                            int& current_row, int& current_col, int& low_row,
                            int& high_row, int& low_col, int& high_col,
                            std::vector<int>& results, bool& possible) {
    if (current_col < low_col) {
      possible = false;
      return;
    }

    while (current_col >= low_col) {
      results.push_back(matrix[current_row][current_col]);
      --current_col;
    }
    ++current_col;
    --current_row;
    high_row = current_row;
    return;
  }

  inline void decrement_row(std::vector<std::vector<int>>& matrix,
                            int& current_row, int& current_col, int& low_row,
                            int& high_row, int& low_col, int& high_col,
                            std::vector<int>& results, bool& possible) {
    std::cout << "decrement_row" << std::endl;
    if (current_row < low_row) {
      possible = false;
      return;
    }

    while (current_row >= low_row) {
      results.push_back(matrix[current_row][current_col]);
      --current_row;
    }
    ++current_row;
    ++current_col;
    low_col = current_col;
    return;
  }

  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    std::vector<int> results;
    if (!matrix.size()) {
      return results;
    }

    int low_row = 0;
    int high_row = matrix.size() - 1;
    int low_col = 0;
    int high_col = matrix[0].size() - 1;
    bool possible = true;  // is it possible to continue
    int current_row = 0;
    int current_col = 0;

    while (possible) {
      increment_col(matrix, current_row, current_col, low_row, high_row,
                    low_col, high_col, results, possible);
      std::cout << current_row << ", " << current_col << std::endl;
      if (!possible) {
        break;
      }
      increment_row(matrix, current_row, current_col, low_row, high_row,
                    low_col, high_col, results, possible);
      std::cout << current_row << ", " << current_col << std::endl;
      if (!possible) {
        break;
      }
      decrement_col(matrix, current_row, current_col, low_row, high_row,
                    low_col, high_col, results, possible);
      std::cout << current_row << ", " << current_col << std::endl;
      if (!possible) {
        break;
      }
      decrement_row(matrix, current_row, current_col, low_row, high_row,
                    low_col, high_col, results, possible);
      std::cout << current_row << ", " << current_col << std::endl;
    }

    return results;
  }
};