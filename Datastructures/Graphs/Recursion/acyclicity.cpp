#include <iostream>
#include <vector>

using std::vector;
using std::pair;

bool checkCyclic(vector<vector<int>> adj, bool* visited, int v) {
  visited[v] = true;

  bool ans = false;
  for(int i=0; i<adj[v].size(); i++) {
    if(visited[adj[v][i]]) {
      return true;
    } else {
      ans = ans || checkCyclic(adj, visited, adj[v][i]);
    }
  }

  visited[v] = false;
  return ans;
}

int acyclic(vector<vector<int> > &adj) {
  bool visited[adj.size()];
  for(int i=0; i<adj.size(); i++) visited[i] = false;

  bool ans = false;
  for(int i=0; i<adj.size(); i++) {
    if(!visited[i]) ans = ans || checkCyclic(adj, visited, i);
  }

  if(ans) return 1;
  
  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
