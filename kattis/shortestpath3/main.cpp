#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <set>
using namespace std;

#define INF (1LL<<60)

struct Edge{
    int64_t u, v, w;
};

vector<int64_t> dist, dist2, from, from2;
vector<vector<int64_t> > graph,
                         edgecost,
                         graph2,
                         edgecost2;
vector<Edge> edges, edges2;
set<int> negset;

bool mybellford(int start, int n){
    dist.assign(n,INF);
    from.assign(n,-1);
    negset.clear();

    dist[start] = 0;

    for(int i = 0; i < n-1; i++){
        for(const Edge e : edges){
            int u = e.u, v = e.v, w = e.w;
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                from[v] = u;
            }
        }
    }
    /**
    for(int i = 0; i < n; i++){
        for(const Edge e : edges){
            int u = e.u, v = e.v, w = e.w;
            if(dist[u] + w < dist[v]){
                dist[v] = -INF;
                from[v] = u;
            }
        }
    }
    **/
}

bool mybellford2(int start, int n){
    dist2.assign(n,-1);
    for(int i = 0; i < n; i++){
        dist2[i] = dist[i];
    }

    for(int i = 0; i < 2*n; i++){
        for(const Edge e : edges){
            int u = e.u, v = e.v, w = e.w;
            if(dist2[u] + w < dist2[v]){
                dist2[v] = dist2[u] + w;
                from[v] = u;
                negset.insert(u);
                negset.insert(v);
            }
        }
    }
}

void bfs(int start, vector<bool>& seen){
    queue<int> Q;
    Q.push(start);
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();
        seen[v] = true;
        for(int i =0; i < graph[v].size(); i++){
            if(!seen[graph[v][i]]){
                Q.push(graph[v][i]);
            }
        }
    }
}

bool neg_cycle(int cur, int start, int n){
    if(dist[start] < 0) return true;
    for(int i = 0; i < n; i++){
        if(cur == start) return false;
        if(cur == -1) return true;
        cur = from[cur];
    }
    return true;
}

void floyd_warshall (vector<vector<int64_t> >& dist){
    for(int64_t k = 0; k < dist.size(); k++){
        for(int64_t i = 0; i < dist.size(); i++){
            for(int64_t j = 0; j < dist.size(); j++){
                if(dist[i][k] != INF && dist[k][j] != INF){
                    if(dist[i][j] > dist[i][k] + dist[k][j]){
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
    for(int64_t i = 0; i < dist.size(); i++){
        for(int64_t j = 0; j < dist.size(); j++){
            for(int64_t k = 0; k < dist.size(); k++){
                if(dist[i][k] != INF && dist[k][j] != INF && dist[k][k] < 0){
                    dist[i][j] = -INF;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    //freopen("out3.txt","r",stdin);
    //cout << INF << endl;
    //cout << super << endl;
    while(true){
        int64_t n, m, q, s;
        cin >> n >> m >> q >> s;
        if(n == 0 && m == 0 && q == 0 && s == 0) break;
        graph.assign(n, vector<int64_t> ());
        edges.clear();
        for(int64_t i = 0; i < m; i++){
            int64_t u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back(v);
            edges.push_back({u,v,w});

        }

        vector<bool> reachable (n);
        bfs(s,reachable);
        mybellford(s,n);
        mybellford2(s,n);
        for(int64_t i = 0; i < q; i++){
            int64_t v;
            cin >> v;
            if(!reachable[v]) cout << "Impossible" << endl;
            else if(negset.find(v) != negset.end()) cout << "-Infinity" << endl;
            else cout << dist[v] << endl;
        }
        cout << endl;
    }
    return 0;
}
