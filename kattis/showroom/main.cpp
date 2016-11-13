#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

#define INF (1LL<<60)
#define endl '\n'
#define mp make_pair

typedef pair<int64_t,int64_t> pii;

vector<int64_t> dist, pred;
vector<vector<pii> > g;

void dijkstra(int64_t u){
	int64_t n = g.size();
	dist.assign(n,INF);
	pred.assign(n, -1);
    dist[u] = 0;
    priority_queue<pii> Q;
    Q.push({-dist[u],u});
    vector<bool> seen (n);

    while(!Q.empty()){
        pii p = Q.top();
        int64_t w = p.second;
        Q.pop();
        if(seen[w]) continue;
	    seen[w] = true;
        for(auto to : g[w]){

        	if(seen[to.first] || dist[to.first] <= dist[w] + to.second)
        		continue;

            dist[to.first] = dist[w] + to.second;
            pred[to.first] = w;
            Q.push({-dist[to.first],to.first});
        }
    }
}

int main() {
	int R, C;
	cin >> R >> C;

	vector<vector<char> > sr(R, vector<char>(C));
	for(int i = 0; i < R; i++) for(int j = 0; j < C; j++) {
		cin >> sr[i][j];
	}

	g.assign(R * C, vector<pii>());
	for(int i = 0; i < R; i++) for(int j = 0; j < C; j++) {
		if(i > 0 && sr[i - 1][j] != '#') g[i * C + j].push_back({ (i - 1) * C + j, sr[i][j] == 'c' });
		if(i < R - 1 && sr[i + 1][j] != '#') g[i * C + j].push_back({ (i + 1) * C + j, sr[i][j] == 'c' });
		if(j > 0 && sr[i][j - 1] != '#') g[i * C + j].push_back({ i * C + j - 1, sr[i][j] == 'c' });
		if(j < C - 1 && sr[i][j + 1] != '#') g[i * C + j].push_back({ i * C + j + 1, sr[i][j] == 'c' });
	}

	int r, c;
	cin >> r >> c;
	r--, c--;
	dijkstra(r * C + c);
	
	int64_t ans = dist[0];
	for(int i = 0; i < R; i++) for(int j = 0; j < C; j++) {
		if(i == 0 || i == R - 1 || j == 0 || j == C - 1) {
			ans = min(ans, dist[i * C + j]);
		}
	}

	cout << ans << endl;

	return 0;
}