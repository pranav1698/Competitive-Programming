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

   int** A = new int*[vertices];
   for(int i=0; i<vertices; i++) {
     A[i] = new int[vertices];
     for(int j=0; j<vertices; j++) A[i][j] = 0;
   }

   int a,b;
   for(int i=0; i<edges; i++) {
     cin >> a >> b;
     A[a][b] = 1;
     A[b][a] = 1;
   }

   queue<int> q;
   q.push(0);
   visited[0] = true;
   while(!q.empty()) {
     int top = q.front();
     q.pop();
     cout << top << endl;

     for(int i=0; i<vertices; i++) {
       if(!visited[i] && A[top][i] == 1) {
         visited[i] = true;
         q.push(i);
       }
     }
   }
 }
