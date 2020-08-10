// Topological Sort for Graph using DFS
// SlothyCoder16
// August 11, 2020

#include <bits/stdc++.h>
using namespace std;

void arrange(vector<vector<int>> adj, bool* visited, stack<int> &res, int v) {
  visited[v] = true;

  for(int i=0; i<adj[v].size(); i++) {
    if(!visited[adj[v][i]]) arrange(adj, visited, res, adj[v][i]);
  }
  res.push(v);
}

bool checkCyclic(vector<vector<int>> adj, bool* visited, int v) {
  visited[v] = true;

  bool ans = false;
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

  vector<vector<int> > adj(vertices, vector<int>());

  int a, b;
  for(int i=0; i<edges; i++) {
    cin >> a >> b;
    adj[a].push_back(b);
  }


  // checking if the graph is cyclic
  bool cyclic = false;
  for(int i=0; i<vertices; i++) {
    if(!visited[i]) cyclic = cyclic || checkCyclic(adj, visited, i);
  }

  if(cyclic) {
    cout << "Cannot be sorted" << endl;
    return 0;
  } else {
    for(int i=0; i<vertices; i++) visited[i] = false;

    stack<int> res;
    for(int i=0; i<vertices; i++) {
      if(!visited[i]) arrange(adj, visited, res, i);
    }

    vector<int> ans;
    while(!res.empty()) {
      ans.push_back(res.top());
      res.pop();
    }

    for(int i=0; i<ans.size(); i++)
      cout << ans[i] << endl;
  }
}
