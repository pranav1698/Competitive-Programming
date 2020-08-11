#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void dfs(vector<vector<int> > &adj, vector<int> &order, bool* visited, int v) {
  visited[v] = true;

  for(int i=0; i<adj[v].size(); i++) {
    if(!visited[adj[v][i]]) dfs(adj, order, visited, adj[v][i]);
  }

  order.push_back(v);
}

vector<int> toposort(vector<vector<int> > adj) {
  vector<int> used(adj.size(), 0);
  vector<int> order;

  bool visited[adj.size()];
  for(int i=0; i<adj.size(); i++) visited[i] = false;

  for(int i=0; i<adj.size(); i++) {
    if(!visited[i]) dfs(adj, order, visited, i);
  }

  for(int i=0; i<order.size(); i++) {
    used[order.size()-i-1] = order[i];
  }
  
  return used;
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
  vector<int> order = toposort(adj);
  for (size_t i = 0; i < order.size(); i++) {
    std::cout << order[i] + 1 << " ";
  }
}
