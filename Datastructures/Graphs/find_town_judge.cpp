// Find town judges using just the adjacency list
// SlothyCoder16
// August 16, 2020

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<vector<int>> adj(N+1, vector<int>());
        vector<int> res(N+1, 0);

        for(int i=0; i<trust.size(); i++){
            adj[trust[i][0]].push_back(trust[i][1]);
            res[trust[i][1]] += 1;
        }

        for(int i=1; i<=N; i++) {
            if(res[i] == N-1 && adj[i].size() == 0){
                return i;
            }
        }

        return -1;
    }
};
