#include <bits/stdc++.h>
using namespace std;


bool search(char** grid, vector<vector<bool>> &visited, string word, int n, int i, int j, int pos) {
  if(word.length() == pos) return true;

  if(i<0 || j<0 || visited[i][j] || i>=n || j>=n || grid[i][j] != word[pos]) {
    return false;
  }

  visited[i][j] = true;
  if(search(grid, visited, word, n, i-1, j, pos+1) ||
  search(grid, visited, word, n, i, j-1, pos+1) ||
  search(grid, visited, word, n, i+1, j, pos+1) ||
  search(grid, visited, word, n, i, j+1, pos+1)){
    return true;
  }
  visited[i][j] = false;

  return false;
}

int main() {
  int n;
  string word;
  cin >> n >> word;
  char** grid = new char*[n];
  vector<vector<bool>> visited(n, vector<bool>(n, false));
  for(int i=0; i<n; i++){
    grid[i] = new char[n];
    for(int j=0; j<n; j++){
      cin >> grid[i][j];
    }
  }

  string res="";
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(grid[i][j] == word[0] && search(grid, visited, word, n, i, j, 0)) {
        res = res + to_string(i+1) + to_string(j+1);
        int count = 1;
        while(count < word.length()) {
          cout << count << endl;
          if(grid[i-1][j] == word[count] && visited[i-1][j]) {
            count++;
            i = i-1;
            res = res + to_string(i+1) + to_string(j+1);
          } else if(grid[i][j-1] == word[count] && visited[i][j-1]) {
            count++;
            j = j-1;
            res = res + to_string(i+1) + to_string(j+1);
          } else if(grid[i+1][j] == word[count] && visited[i+1][j]) {
            count++;
            i = i + 1;
            res = res + to_string(i+1) + to_string(j+1);
          }  else if(grid[i][j+1] == word[count] && visited[i][j+1]) {
            count++;
            j = j+1;
            res = res + to_string(i+1) + to_string(j+1);
          }
        }
      }
    }
  }

  cout << res << endl;


  return false;
}
