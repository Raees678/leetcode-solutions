class Solution {
 public:
  std::pair<int, int> convert(int i, int j, int size) {
    return std::make_pair(j, size - i - 1);
  }

  void rotate(std::vector<std::vector<int>>& matrix) {
    for (int i = 0; i < (matrix.size()) / 2; ++i) {
      for (int j = i; j < matrix.size() - i - 1; ++j) {
        int temp = matrix[i][j];
        std::pair<int, int> new_coords = convert(i, j, matrix.size());
        for (int k = 0; k < 4; ++k) {
          int new_temp = matrix[new_coords.first][new_coords.second];
          matrix[new_coords.first][new_coords.second] = temp;
          temp = new_temp;
          new_coords =
              convert(new_coords.first, new_coords.second, matrix.size());
        }
      }
    }
  }
};

int main(void) {
  std::vector<std::vector<int>> matrix{{1, 2}, {3, 4}};
  Solution s;
  s.rotate(matrix);
  for (int i = 0; i < matrix.size(); ++i) {
    for (int j = 0; j < matrix.size(); ++j) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}