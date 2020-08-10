// DFS preorder using Adjancency Matrix
// SlothyCoder16
// August 10, 2020

#include <bits/stdc++.h>
using namespace std;

void explore(int** A, int vertices, bool* visited, int v) {
  visited[v] = true;
  cout << v << endl;
  for(int i=0; i<vertices; i++) {
    if(!visited[i]) {
        if(A[v][i] == 1) explore(A, vertices, visited, i);
    }
  }
}


int main() {
  int start;
  cin >> start;
  int vertices;
  cin >> vertices;
  int edges;
  cin >> edges;
  int a, b;
  bool visited[vertices];
  int** A= new int*[vertices];

  for(int i=0; i<vertices; i++){
    A[i] = new int[vertices];
    for(int j=0; j<vertices; j++)
      A[i][j] = 0;
  }

  for(int i=0; i<edges; i++) {
    cin >> a >> b;
    A[a][b] = 1;
    A[b][a] = 1;
  }

  for(int i=0; i<vertices; i++){
    if(!visited[i]) explore(A, vertices, visited, i);
  }
}
