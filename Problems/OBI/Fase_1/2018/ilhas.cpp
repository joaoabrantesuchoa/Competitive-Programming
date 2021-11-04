#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

#define INF 1000000000

int n,m,u,v,p,source;
vector<ii> adj_list[1050];
vector<int> dist(10000, INF);
priority_queue<ii, vector<ii>, greater<ii>> pq;

void dijkstra(int source) {
    dist[source] = 0;
    pq.push({0,source});

    while(!pq.empty()) {
        int actual = pq.top().second;
        int dist_actual = pq.top().first;
        pq.pop();
        for (auto node: adj_list[actual]) {
            if (node.first + dist[actual] < dist[node.second]) {
                dist[node.second] = node.first + dist[actual];
                pq.push({dist[node.first], node.second});
            } 
        }
    }
}


int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> u >> v >> p;
        adj_list[u].push_back({p,v});
        adj_list[v].push_back({p,u});
    }
    cin >> source;

    dijkstra(source);

    int max_dist = 0;
    int min_dist = INF;

    for (int i = 1; i <= n; i++) {
        if(max_dist < dist[i] && dist[i] != INF) max_dist = max(max_dist, dist[i]);
        if(min_dist > dist[i] && dist[i] != 0) min_dist = min(min_dist, dist[i]); 
    }

    cout << max_dist - min_dist << "\n";

    return 0;
}