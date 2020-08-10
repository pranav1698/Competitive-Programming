// DFS Postorder using Recursion (Adjacency List)
// SlothyCoder16
// August 10, 2020

#include <bits/stdc++.h>
using namespace std;

void explore(vector<vector<int>> edgeList, bool* visited, int v) {
  visited[v] = true;
  for(int i=0; i<edgeList[v].size(); i++) {
    if(!visited[edgeList[v][i]]) explore(edgeList, visited, edgeList[v][i]);
  }
  cout << v << endl;
}

int main() {
  int start;
  cin >> start;
  int vertices;
  cin >> vertices;
  int edges;
  cin >> edges;

  vector<vector<int>> edgeList;
  bool visited[vertices];
  for(int i=0; i<vertices; i++) visited[i] = false;

  int a,b;
  for(int i=0; i<=100; i++) edgeList.push_back({});

  for(int i=0; i<edges; i++){
    cin >> a >> b;
    edgeList[a].push_back(b);
    edgeList[b].push_back(a);
  }

  for(int i=0; i<vertices; i++)
    if(!visited[i]) explore(edgeList, visited, i);
}
