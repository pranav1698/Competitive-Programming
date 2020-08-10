// DFS Preorder traversal using stack
// SlothyCoder16
// August 10, 2020

#include <bits/stdc++.h>
using namespace std;

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
  for(int i=0; i<edges; i++) edgeList.push_back({});

  for(int i=0; i<edges; i++){
    cin >> a >> b;
    edgeList[a].push_back(b);
    edgeList[b].push_back(a);
  }

  // for(int i=0; i<edgeList.size(); i++)
  //   for(int j=0; j<edgeList[i].size(); j++)
  //     cout << edgeList[i][j] << endl;

  // int i=start;
  // do{
  //   if(!visited[i]) explore(edgeList, visited, i);
  //   i = (i+1);
  // } while(i<vertices);

  stack<int> s;
  s.push(start);
  visited[start] = true;
  cout << start << endl;

  while(!s.empty()) {
    int top = s.top();
    bool flag = false;

    for(int i=0; i<edgeList[top].size(); i++) {
      if(!visited[edgeList[top][i]]){
        visited[edgeList[top][i]] = true;
        s.push(edgeList[top][i]);
        cout << edgeList[top][i] << endl;
        flag = true;
        break;
      }
    }

    if(!flag) s.pop();
  }

}
