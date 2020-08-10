#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void explore(vector<vector<int> > &adj, bool* visited, int v) {
  visited[v] = true;
  for(int i=0; i<adj[v].size(); i++){
    if(!visited[adj[v][i]]) explore(adj, visited, adj[v][i]);
  }
}


int reach(vector<vector<int> > &adj, int x, int y) {
  bool visited[adj.size()];
  for(int i=0; i<adj.size(); i++) visited[i] = false;

  for(int i=0; i<adj.size(); i++) {
    if(!visited[i]) {
      explore(adj, visited, i);
      if(visited[x] && !visited[y]) return 0;
      if(!visited[x] && visited[y]) return 0;
    }
  }
  return 1;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}
