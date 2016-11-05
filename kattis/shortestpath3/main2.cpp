#include <vector>
#include <iostream>
#include <climits>

using namespace std;

struct Edge {
    int u, v, w;
};

int n, m, q, s;
vector<Edge> edges;
vector<int> dist;

void bellman_ford() {
    for(int i = 0; i < n - 1; i++) {
        for(const Edge &e : edges) {
            if(dist[e.u] != INT_MAX && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

    for(int i = 0; i <= n; i++) {
        for(const Edge &e : edges) {
            if(dist[e.u] != INT_MAX && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = -INT_MAX;
            }
        }
    }
}

int main() {
    while(true) {
        edges.clear();
        dist = vector<int>(1000, INT_MAX);

        cin >> n >> m >> q >> s;
        if(!n && !m && !q && !s) break;
        
        dist[s] = 0;    
    
        for(int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
        }

        bellman_ford();

        for(int i = 0; i < q; i++) {
            int t;
            cin >> t;

            if(dist[t] == INT_MAX) cout << "Impossible" << endl;
            else if(dist[t] == -INT_MAX) cout << "-Infinity" << endl;
            else cout << dist[t] << endl;
        }
        cout << endl;
    }

    return 0;
}
