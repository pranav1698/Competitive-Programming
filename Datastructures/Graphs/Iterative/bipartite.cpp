// Check if the given graph is Bipartite (adjacency matrix)
// SlothyCoder16
// August 13, 2020

#include <bits/stdc++.h>
using namespace std;

bool checkBipartite(vector<vector<int>> adj, int* dist, int node) {
  dist[node] = 0;
  queue<int> q;
  q.push(node);

  while(!q.empty()) {
    int u = q.front();
    q.pop();

    for(int x: adj[u]) {
      if(dist[x] == dist[u]) return false;

      if(dist[x] == INT_MAX) {
        dist[x] = dist[u] + 1;
        q.push(x);
      }
    }
  }

  return true;
}

int bipartite(vector<vector<int> > &adj) {
  int dist[adj.size()];
  for(int i=0; i<adj.size(); i++) dist[i] = INT_MAX;

  bool ans = true;
  for(int i=0; i<adj.size(); i++){
    if(dist[i] == INT_MAX) {
      ans = ans && checkBipartite(adj, dist, i);
    }
  }

  return ans;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
