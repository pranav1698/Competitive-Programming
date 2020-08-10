#include <bits/stdc++.h>
using namespace std;

void explore(vector<vector<int>> adj, bool* visited, vector<int> &res, int v) {
  visited[v] = true;
  res.push_back(v);
  for(int i=0; i<adj[v].size(); i++) {
    if(!visited[adj[v][i]]) explore(adj, visited, res, adj[v][i]);
  }
}

void dfsR(vector<vector<int>> adjR, bool* visited, stack<int> &s, int v) {
  visited[v] = true;
  for(int i=0; i<adjR[v].size(); i++) {
    if(!visited[adjR[v][i]]) dfsR(adjR, visited, s, adjR[v][i]);
  }

  s.push(v);
}

int main() {
  int vertices;
  cin >> vertices;
  int edges;
  cin >> edges;

  vector<vector<int>> adj(vertices, vector<int>());
  vector<vector<int>> adjR(vertices, vector<int>());
  bool visited[vertices];
  for(int i=0; i<vertices; i++) visited[i] = false;

  int a,b;
  for(int i=0; i<edges; i++) {
    cin >> a >> b;
    adj[a].push_back(b);
    adjR[b].push_back(a);
  }

  stack<int> s;
  for(int i=0; i<vertices; i++)
    if(!visited[i]) dfsR(adjR, visited, s, i);

  vector<int> reverseP;
  while(!s.empty()) {
    reverseP.push_back(s.top());
    s.pop();
  }

  for(int i=0; i<vertices; i++) visited[i] = false;

  vector<vector<int>> ans;
  for(int i=0; i<reverseP.size(); i++){
    if(!visited[reverseP[i]]) {
      vector<int> res;
      explore(adj, visited, res, reverseP[i]);
      ans.push_back(res);
    }
  }

  cout << ans.size() << endl;
}
