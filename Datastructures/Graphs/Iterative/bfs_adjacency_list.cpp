// BFS traversal using adjacency matrix
// SlothyCoder16
// August 10, 2020


#include <bits/stdc++.h>
using namespace std;

int main() {
  int vertices;
  cin >> vertices;
  int edges;
  cin >> edges;

  bool visited[vertices];
  for(int i=0; i<vertices; i++) visited[i] = false;

  vector<vector<int>> edgeList;
  for(int i=0; i<=1000; i++) edgeList.push_back({});

  int a,b;
  for(int i=0; i<edges; i++) {
    cin >> a >> b;
    edgeList[a].push_back(b);
    edgeList[b].push_back(a);
  }

  queue<int> q;
  q.push(0);
  visited[0] = true;

  while(!q.empty()) {
    int top = q.front();
    q.pop();
    cout << top << endl;

    for(int i=0; i<edgeList[top].size(); i++) {
      if(!visited[edgeList[top][i]]){
        visited[edgeList[top][i]] = true;
        q.push(edgeList[top][i]);
      }
    }
  }
}
