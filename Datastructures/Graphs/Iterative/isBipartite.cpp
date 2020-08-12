// Check if the given graph is Bipartite (adjacency matrix)
// SlothyCoder16
// August 13, 2020

bool checkBipartite(int G[][MAX], int V, int node, int* dist) {
    queue<int> q;
    dist[node] = 0;
    q.push(node);

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int i=0; i<V; i++) {
            if(G[u][i] == 1) {
                if(dist[i] == dist[u]) {
                    return false;
                }
                if(dist[i] == INT_MAX) {
                    dist[i] = dist[u] + 1;
                    q.push(i);
                }
            }
        }
    }

    return true;
}

bool isBipartite(int G[][MAX],int V)
{
    int dist[V];
    for(int i=0; i<V; i++) dist[i] = INT_MAX;
    bool ans = true;
    for(int i=0; i<V; i++) {
        if(dist[i] == INT_MAX) {
            ans = ans && checkBipartite(G, V, i, dist);
        }
    }

    return ans;
}
