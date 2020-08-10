#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void explore(vector<vector<int>> &adj, bool* visited, int v) {
  visited[v] = true;
  for(int i=0; i<adj[v].size(); i++) {
    if(!visited[adj[v][i]]) explore(adj, visited, adj[v][i]);
  }
}


int number_of_components(vector<vector<int> > &adj) {
  int res = 0;
  bool visited[adj.size()];
  for(int i=0; i<adj.size(); i++) visited[i] = false;

  for(int i=0; i<adj.size(); i++) {
      if(!visited[i]){
        res++;
        explore(adj, visited, i);
      }
  }
  return res;
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
  std::cout << number_of_components(adj);
}
