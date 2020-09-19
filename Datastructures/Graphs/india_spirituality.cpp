#include <bits/stdc++.h>
using namespace std;


void setSpiritual(vector<vector<char>> &a, int r, int c, int n, int m) {
    if(r>=0 && c>=0 && r<n && c<m && a[r][c]!='*') a[r][c] = 's';
}

bool canTraverse(vector<vector<char>> &a, int r, int c, int n, int m, vector<vector<bool>> &visited) {
    return (r>=0) && (r<n) && (c>=0) && (c<m) && (a[r][c]=='s' && visited[r][c]==false);
}

void dfs(vector<vector<char>> &a, int r, int c, int n, int m, vector<vector<bool>> &visited, int &count) {
    visited[r][c]=true;

    if(canTraverse(a, r+1, c, n, m, visited)) {
        count++;
        dfs(a, r+1, c, n, m, visited, count);
    }

    if(canTraverse(a, r+1, c+1, n, m, visited)) {
        count++;
        dfs(a, r+1, c+1, n, m, visited, count);
    }

    if(canTraverse(a, r+1, c-1, n, m, visited)) {
        count++;
        dfs(a, r+1, c-1, n, m, visited, count);
    }

    if(canTraverse(a, r, c+1, n, m, visited)) {
        count++;
        dfs(a, r, c+1, n, m, visited, count);
    }

    if(canTraverse(a, r, c-1, n, m, visited)) {
        count++;
        dfs(a, r, c-1, n, m, visited, count);
    }

    if(canTraverse(a, r-1, c, n, m, visited)) {
        count++;
        dfs(a, r-1, c, n, m, visited, count);
    }

    if(canTraverse(a, r-1, c-1, n, m, visited)) {
        count++;
        dfs(a, r-1, c-1, n, m, visited, count);
    }

    if(canTraverse(a, r-1, c+1, n, m, visited)) {
        count++;
        dfs(a, r-1, c+1, n, m, visited, count);
    }
}

int maxCities(vector<vector<char>> &a, int n, int m)
{
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(a[i][j] == '*') {
              setSpiritual(a, i-1, j, n, m);
              setSpiritual(a, i-1, j-1, n, m);
              setSpiritual(a, i-1, j+1, n, m);
              setSpiritual(a, i, j-1, n, m);
              setSpiritual(a, i+1, j-1, n, m);
              setSpiritual(a, i+1, j, n, m);
              setSpiritual(a, i+1, j+1, n, m);
              setSpiritual(a, i, j+1, n, m);
            }
        }
    }

    int ans=0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(a[i][j] == 's' && !visited[i][j]) {
                int citiesVisited = 1;
                dfs(a, i, j, n, m, visited, citiesVisited);
                ans = max(ans, citiesVisited);
            }
        }
    }

    return ans;
}


int main()
{


    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<char>> a(n, vector<char>(m));

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> a[i][j];
            }
        }

        cout << maxCities(a, n, m) << "\n";

    }


    return 0;
}
