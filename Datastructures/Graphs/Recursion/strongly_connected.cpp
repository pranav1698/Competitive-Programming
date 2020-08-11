#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using std::vector;
using std::pair;
using std:: stack;
using namespace std;

void dfs(vector<vector<int>> adjR, bool* visited, stack<int> &s, int v) {
  visited[v] = true;
  for(int i=0; i<adjR[v].size(); i++){
    if(!visited[adjR[v][i]]) dfs(adjR, visited, s, adjR[v][i]);
  }
  s.push(v);
}

void explore(vector<vector<int>> adj, bool* visited, int v) {
  visited[v] = true;
  for(int i=0; i<adj[v].size(); i++) {
    if(!visited[adj[v][i]]) explore(adj, visited, adj[v][i]);
  }
}


int number_of_strongly_connected_components(vector<vector<int> > adj) {
  int result = 0;
  bool visited[adj.size()];
  for(int i=0; i<adj.size(); i++) visited[i] = false;

  vector<vector<int>> adjR(adj.size(), vector<int>());
  for(int i=0; i<adj.size(); i++) {
    for(int x: adj[i]){
      adjR[x].push_back(i);
    }
  }

  stack<int> s;
  for(int i=0; i<adjR.size(); i++) {
    if(!visited[i]) dfs(adjR, visited, s, i);
  }

  for(int i=0; i<adj.size(); i++) visited[i] = false;
  while(!s.empty()) {
    int top = s.top();
    s.pop();

    if(!visited[top]) {
      result = result + 1;
      explore(adj, visited, top);
    }
  }

  return result;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << number_of_strongly_connected_components(adj);
}
