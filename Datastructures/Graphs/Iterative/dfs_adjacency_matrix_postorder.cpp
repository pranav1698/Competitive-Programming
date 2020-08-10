// DFS postorder using Adjancency Matrix (Iterative)
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

  bool visited[vertices];
  for(int i=0; i<vertices; i++) visited[i] = false;

  int** A = new int*[vertices];
  for(int i=0; i<vertices; i++) {
    A[i] = new int[vertices];
    for(int j=0; j<vertices; j++) A[i][j] = 0;
  }

  int a, b;
  for(int i=0; i<edges; i++) {
    cin >> a >> b;
    A[a][b] = 1;
    A[b][a] = 1;
  }

  stack<int> s;
  s.push(start);
  visited[start] = true;

  while(!s.empty()) {
    int top=s.top();
    bool flag = false;
    for(int i=0; i<vertices; i++) {
      if(!visited[i] && A[top][i] == 1) {
        visited[i] = true;
        s.push(i);
        flag = true;
        break;
      }
    }
    if(!flag){
      cout << top << endl;
      s.pop();
    }
  }
}
