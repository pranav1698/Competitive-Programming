// Minimum shortest path in a graph having no negative edges(Dijkstra)
// August 14, 2020
// SlothyCoder16

#include <bits/stdc++.h>
using namespace std;

class compare {
public:
  bool operator()(const pair<int, int> p1, const pair<int, int> p2) {
    return p1.second > p2.second;
  }
};

long long distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  vector<int> dist(adj.size(), INT_MAX);
  dist[s] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
  pq.push({s, dist[s]});

  while(!pq.empty()) {
      int u = pq.top().first;
      pq.pop();

      for(int i=0; i<adj[u].size(); i++) {
        if(dist[adj[u][i]] > (dist[u] + cost[u][i])) {
          dist[adj[u][i]] = dist[u] + cost[u][i];
          pq.push({adj[u][i], dist[adj[u][i]]});
        }
      }
  }

  if(dist[t] != INT_MAX) return dist[t];

  return -1;
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
