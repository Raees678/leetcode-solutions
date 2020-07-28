class Solution {
 public:
  enum state { UNVISITED, VISITED };

  std::vector<std::pair<int, int>> getNeighbours(
      int row, int col, std::vector<std::vector<char>>& grid,
      std::vector<std::vector<state>>& visited) {
    std::vector<std::pair<int, int>> results;
    if (row - 1 >= 0 && visited[row - 1][col] == UNVISITED &&
        grid[row - 1][col] == '1') {
      results.push_back(std::make_pair(row - 1, col));
    }
    if (row + 1 < grid.size() && visited[row + 1][col] == UNVISITED &&
        grid[row + 1][col] == '1') {
      results.push_back(std::make_pair(row + 1, col));
    }
    if (col - 1 >= 0 && visited[row][col - 1] == UNVISITED &&
        grid[row][col - 1] == '1') {
      results.push_back(std::make_pair(row, col - 1));
    }
    if (col + 1 < grid[row].size() && visited[row][col + 1] == UNVISITED &&
        grid[row][col + 1] == '1') {
      results.push_back(std::make_pair(row, col + 1));
    }
    return results;
  }

  bool bfsVisit(int row, int col, std::vector<std::vector<char>>& grid,
                std::vector<std::vector<state>>& visited) {
    std::queue<std::pair<int, int>> queue;
    bool bfs_started = false;
    if (grid[row][col] == '1') {
      queue.push(std::make_pair(row, col));
      bfs_started = true;
    }
    visited[row][col] = VISITED;

    while (!queue.empty()) {
      std::pair<int, int> coords = queue.front();
      queue.pop();
      int row = coords.first;
      int col = coords.second;

      std::vector<std::pair<int, int>> neighbours =
          getNeighbours(row, col, grid, visited);
      for (std::pair<int, int>& neighbour_coord : neighbours) {
        queue.push(neighbour_coord);
        int neighbour_row = neighbour_coord.first;
        int neighbour_col = neighbour_coord.second;
        visited[neighbour_row][neighbour_col] = VISITED;
      }
    }
    return bfs_started;
  }

  int numIslands(vector<vector<char>>& grid) {
    // this is essentially to find the number of strongly connected components
    if (!grid.size()) {
      return 0;
    }
    int m = grid.size();
    int n = grid[0].size();
    std::vector<std::vector<state>> visited(m,
                                            std::vector<state>(n, UNVISITED));

    int number_of_islands = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (visited[i][j] == UNVISITED) {
          bool bfs_started = bfsVisit(i, j, grid, visited);
          if (bfs_started) {
            ++number_of_islands;
          }
        }
      }
    }

    return number_of_islands;
  }
};