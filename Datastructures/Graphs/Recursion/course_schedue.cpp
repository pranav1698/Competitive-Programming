// How to check if graph is cyclic?
// SlothyCoder16
// August 15, 2020

class Solution {
public:
    bool checkCyclic(vector<vector<int>> &adj, vector<int> &visited, int v) {
        if(visited[v] == 1) return true;
        if(visited[v] == 2) return false;

        visited[v] = 1;
        for(int i=0; i<adj[v].size(); i++)
            if(checkCyclic(adj, visited, adj[v][i])) return true;

        visited[v] = 2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());

        for(int i=0; i<prerequisites.size(); i++)
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);

        vector<int> visited(numCourses, 0);
        bool res = false;
        for(int i=0; i<numCourses; i++)
            if(checkCyclic(adj, visited, i)) return false;

        return true;
    }
};
