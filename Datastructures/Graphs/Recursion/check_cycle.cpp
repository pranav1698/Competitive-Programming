// Checking if graph is cyclic or not using DFS
// SlothyCoder16
// August 11, 2020

#include <bits/stdc++.h>
using namespace std;

bool checkCyclic(vector<vector<int>> adj, bool* visited, int v) {
    bool ans = false;

    visited[v] = true;
    for(int i=0; i<adj[v].size(); i++) {
        if(visited[adj[v][i]]){
            return true;
        } else {
            ans = ans || checkCyclic(adj, visited, adj[v][i]);
        }
    }

    visited[v] = false;
    return ans;
}


int main() {
  int vertices;
  cin >> vertices;
  int edges;
  cin >> edges;

  bool visited[vertices];
  for(int i=0; i<vertices; i++) visited[i] = false;

  vector<vector<int>> adjList;
  for(int i=0; i<=1000; i++) adjList.push_back({});

  int a,b;
  for(int i=0; i<edges; i++) {
    cin >> a >> b;;
    adjList[a].push_back(b);
  }

  bool ans = false;
  for(int i=0; i<vertices; i++) {
    if(!visited[i]) ans = ans || checkCyclic(adjList, visited, i);
  }

  cout << ans << endl;
}
