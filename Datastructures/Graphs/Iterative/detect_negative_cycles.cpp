// Detecting negative cycles in the Graph with negative weighted graph
// SlothyCoder16
// August 14, 2020

#include <bits/stdc++.h>
using namespace std;

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  vector<int> dist(adj.size(), 100000);

  dist[0]=0;
  int V = adj.size();

  int k=1;
  while(k != V) {
    for(int i=0; i<adj.size(); i++) {
      for(int j=0; j<adj[i].size(); j++) {
        if(dist[adj[i][j]] > (dist[i] + cost[i][j])) {
          dist[adj[i][j]] = dist[i] + cost[i][j];
        }
      }
    }
    k++;
  }

  for(int i=0; i<adj.size(); i++) {
    for(int j=0; j<adj[i].size(); j++) {
      if(dist[adj[i][j]] > (dist[i] + cost[i][j])) {
        return 1;
      }
    }
  }

  return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
}
