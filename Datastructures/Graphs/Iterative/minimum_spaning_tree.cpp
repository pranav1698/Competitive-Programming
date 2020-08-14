class compare {
public:
    bool operator()(const pair<int, int> p1, const pair<int, int> p2) {
        return p1.second > p2.second;
    }
};

int spanningTree(int V, int E, vector<vector<int>> &graph) {
    vector<int> cost(V, 1000000);
    vector<bool> visited(V, false);
    int root = 0;
    cost[root] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    int res = 0;

    for(int i=0; i<V; i++) pq.push({i, cost[i]});

    while(!pq.empty()) {
        int u = pq.top().first;
        pq.pop();
        visited[u] = true;

        for(int z=0; z<V; z++) {
            if(graph[u][z] != INT_MAX) {
                if(!visited[z] && cost[z] > graph[u][z]){
                    cost[z] = graph[u][z];
                    pq.push({z, cost[z]});
                }
            }
        }
    }

    for(int i=0; i<V; i++){
        res = res + cost[i];
    }

    return res;
}
