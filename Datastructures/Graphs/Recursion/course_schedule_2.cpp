// Topological Sort of graph
// SlothyCoder16
// August 15, 2020

class Solution {
public:
    bool has_cycle(vector<vector<int>> &adj, vector<int> &visited, int v, vector<int> &res) {
        if(visited[v] == 1) return true;
        if(visited[v] == 2) return false;

        visited[v] = 1;
        for(int i=0; i<adj[v].size(); i++)
            if(has_cycle(adj, visited, adj[v][i], res)) return true;

        visited[v] = 2;
        res.push_back(v);

        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> visited(numCourses, 0);

        for(int i=0; i<prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for(int i=0; i<numCourses; ++i)
            if(has_cycle(adj, visited, i, res)) return {};

        reverse(res.begin(), res.end());
        return res;
    }
};
