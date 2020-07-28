class Solution {
 public:
  enum state { VISITED, VISITING, UNVISITED };
  void dfsFindLowLink(int node, int parent, int& current_id,
                      std::vector<int>& ids,
                      const std::vector<std::vector<int>>& graph,
                      std::vector<int>& low_link,
                      std::vector<state>& node_state) {
    node_state[node] = VISITING;
    ids[node] = current_id;
    low_link[node] = current_id;
    int node_lowest_link = current_id;
    current_id += 1;

    for (int i = 0; i < graph[node].size(); ++i) {
      int neighbour = graph[node][i];
      if (neighbour == parent) {
        continue;
      }
      if (node_state[neighbour] == UNVISITED) {
        dfsFindLowLink(neighbour, node, current_id, ids, graph, low_link,
                       node_state);
      }
      // if a node is visiting its low_link is stored as its current_id
      // if a node is visited its low_link is computed and stored
      int& neighbour_lowest_link = low_link[neighbour];
      node_lowest_link = std::min(node_lowest_link, neighbour_lowest_link);
    }
    low_link[node] = node_lowest_link;
    node_state[node] = VISITED;
  }

  inline void createGraph(std::vector<std::vector<int>>& graph,
                          const std::vector<std::vector<int>>& connections) {
    for (const std::vector<int>& edge : connections) {
      const int& source = edge[0];
      const int& dest = edge[1];
      graph[source].push_back(dest);
      graph[dest].push_back(source);
    }
  }

  std::vector<std::vector<int>> criticalConnections(
      int n, std::vector<std::vector<int>>& connections) {
    std::vector<state> node_state(n, UNVISITED);
    // assign each node a low_link i.e. the lowest node it can traverse to,
    // filled up as the  DFS  traverses
    std::vector<int> low_link(n, -1);
    // assign each node an increasing id, filled up as the DFS traverses
    std::vector<int> ids(n, INT_MAX);
    int current_id = 0;

    std::vector<std::vector<int>> graph(n, std::vector<int>());
    createGraph(graph, connections);
    // since we know the graph is connected just do the dfs on the root node
    dfsFindLowLink(0, -1, current_id, ids, graph, low_link, node_state);

    std::vector<std::vector<int>> results;
    for (int i = 0; i < connections.size(); ++i) {
      int& source = connections[i][0];
      int& dest = connections[i][1];
      if (ids[source] < low_link[dest]) {
        results.push_back({source, dest});
      } else if (ids[dest] < low_link[source]) {
        results.push_back({dest, source});
      }
    }

    return results;
  }
};