// - the key insight into this problem
// - each graph can only have 1 or 2 min height tree roots
// - these roots are the nodes from which the farthest leaf node has minimum
// distance
// - keep trimming the leaf nodes from the graph, until at most two remain
// - the remaining nodes are the min height roots
// - THINK OF THIS SOLUTION GRAPHICALLY AND IT MAKES SENSE!

class Solution {
 public:
  enum state { DELETED, TAGGED, PRESENT };
  void createGraph(std::vector<std::vector<int>>& graph,
                   std::vector<int>& degree,
                   const std::vector<std::vector<int>>& edges) {
    for (int i = 0; i < edges.size(); ++i) {
      int source = edges[i][0];
      int destination = edges[i][1];
      graph[source].push_back(destination);
      graph[destination].push_back(source);
      ++degree[source];
      ++degree[destination];
    }
  }

  void trimLeafsBFS(std::vector<std::vector<int>>& graph,
                    std::vector<int>& degree, std::vector<state>& state) {
    std::queue<int> leaves;
    for (int i = 0; i < degree.size(); ++i) {
      if (degree[i] == 1) {
        // push all nodes with degree 1 i.e. leaf nodes into the queue
        leaves.push(i);
      }
    }

    int nodes_remaining = graph.size();
    while (nodes_remaining > 2) {
      int number_of_leaves = leaves.size();
      for (int i = 0; i < number_of_leaves; ++i) {
        int leaf = leaves.front();
        leaves.pop();
        --nodes_remaining;
        // reduce the degree of the leaf i.e. it is now disconnected
        --degree[leaf];
        // mark it as deleted so that it is never added. again in the BFS
        state[leaf] = DELETED;
        // zero out the edges that connect to this leaf
        for (int j = 0; j < graph[leaf].size(); ++j) {
          int possible_leaf = graph[leaf][j];
          // for all undeleted edges
          if (state[possible_leaf] == PRESENT) {
            // reduce the degree of the nodes connecting to this one
            --degree[possible_leaf];
            // and if any of the other nodes that connect to this leaf are now
            // leaves push them onto the queue
            if (degree[possible_leaf] == 1) {
              state[possible_leaf] = TAGGED;
              leaves.push(possible_leaf);
            }
          }
        }
      }
    }
    // at this point only up to 2 nodes will not be removed and have a degree >
    // 0
  }

  std::vector<int> findMinHeightTrees(int n,
                                      std::vector<std::vector<int>>& edges) {
    std::vector<std::vector<int>> graph(n, std::vector<int>());
    std::vector<int> degree(n, 0);
    std::vector<state> state(n, PRESENT);
    createGraph(graph, degree, edges);
    trimLeafsBFS(graph, degree, state);

    std::vector<int> results;
    for (int i = 0; i < state.size(); ++i) {
      if (state[i] != DELETED) {
        results.push_back(i);
      }
    }
    return results;
  }
};