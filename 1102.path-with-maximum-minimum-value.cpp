// Given a matrix of integers A with R rows and C columns, find the maximum
// score of a path starting at [0,0] and ending at [R-1,C-1].
//
// The score of a path is the minimum value in that path.  For example, the
// value of the path 8 &rarr;  4 &rarr;  5 &rarr;  9 is 4.
//
// A path moves some number of times from one visited cell to any neighbouring
// unvisited cell in one of the 4 cardinal directions (north, east, west,
// south).
//
//
//
// --------------------------------------------------
//
// Example 1:
//
//
//
//
// Input: [[5,4,5],[1,2,6],[7,4,6]]
// Output: 4
// Explanation:
// The path with the maximum score is highlighted in yellow.
//
//
// --------------------------------------------------
//
// Example 2:
//
//
//
//
// Input: [[2,2,1,2,2,2],[1,2,2,2,1,2]]
// Output: 2
//
// --------------------------------------------------
//
// Example 3:
//
//
//
//
// Input:
// [[3,4,6,3,4],[0,2,1,1,7],[8,8,3,2,7],[3,2,4,9,8],[4,1,2,0,0],[4,6,5,4,3]]
// Output: 3
//
//
//
// * * * * * * * * * * * * * * * * * * * * * * * * *
//
// Note:
//
//
// 	1 <= R, C <= 100
// 	0 <= A[i][j] <= 10^9
//
//
class Solution {
 public:
  std::vector<std::vector<int>> neighbour_basis{
      {0, 1}, {1, 0}, {-1, 0}, {0, -1}};

  enum state { UNVISITED, VISITED };

  inline std::vector<std::vector<int>> findNeighbours(
      int row, int col, std::vector<std::vector<int>>& A,
      std::vector<std::vector<state>>& states) {
    std::vector<std::vector<int>> neighbours;
    for (int i = 0; i < 4; ++i) {
      int new_row = row + neighbour_basis[i][0];
      int new_col = col + neighbour_basis[i][1];
      if (new_row >= 0 && new_row < A.size() && new_col >= 0 &&
          new_col < A[new_row].size() &&
          states[new_row][new_col] == UNVISITED) {
        neighbours.push_back(std::vector<int>{new_row, new_col});
      }
    }
    return neighbours;
  }

  struct CompareScore {
    bool operator()(const std::vector<int>& a, const std::vector<int>& b) {
      return a[2] < b[2];
    }
  };

  int maximumMinimumPath(std::vector<std::vector<int>>& A) {
    // we use djikstras algorithm. to find the single source shortest path
    std::vector<std::vector<int>> scores(A.size(),
                                         std::vector<int>(A[0].size(), -1));
    std::priority_queue<std::vector<int>> queue;
    std::vector<std::vector<state>> states(
        A.size(), std::vector<state>(A[0].size(), UNVISITED));
    queue.push(std::vector<int>{0, 0, A[0][0]});

    while (!queue.empty()) {
      std::vector<int> current_node = queue.top();
      queue.pop();
      int row = current_node[0];
      int col = current_node[1];
      int score = current_node[2];
      // if the node obtained shows that the score is lesser than the recorded
      // score dont try to compute its neighbours scores, because we have
      // already done it with a better recorded score, since better scores are
      // popped from the priority queue first
      if (score <= scores[row][col]) {
        continue;
      }
      scores[row][col] = score;
      if (row == A.size() - 1 && col == A[0].size() - 1) {
        break;
      }
      std::vector<std::vector<int>> neighbours =
          findNeighbours(row, col, A, states);
      for (int i = 0; i < neighbours.size(); ++i) {
        // for all neighbours calculate the score of getting to them and update
        // the score table
        int neighbour_row = neighbours[i][0];
        int neighbour_col = neighbours[i][1];
        int neighbour_score = std::min(score, A[neighbour_row][neighbour_col]);
        states[neighbour_row][neighbour_col] = VISITED;
        queue.push(
            std::vector<int>{neighbour_row, neighbour_col, neighbour_score});
      }
    }

    return scores[A.size() - 1][A[0].size() - 1];
  }
};