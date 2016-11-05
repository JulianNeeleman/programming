#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <iomanip>
#include <algorithm>
#include <map>
#include <random>
#include <cstdint>
#include <sstream>

using namespace std;

bool found = false;
int N;
vector<int> cs;
vector<set<int> > g;

void backtrack(int u) {
	if(u == N) {
		if(!found) {
			for(int i = 0; i < N; i++) {
				cout << i + 1 << " " << cs[i] + 1 << endl;
			}
		}
		found = true;
		return;
	}

	vector<bool> pos(4, true);
	for(const int &v : g[u]) {
		if(cs[v] >= 0) pos[cs[v]] = false;
	}

	for(int c = 0; c < 4; c++) {
		if(pos[c]) {
			cs[u] = c;
			backtrack(u + 1);
		}
	}	
	cs[u] = -1;
}

int main() {
	cin >> N;
	cs.assign(N, -1);
	g.assign(N, set<int>());

	int u, v;
	char t;
	while(cin >> u >> t >> v) {
		if(u != v) {
			g[u - 1].insert(v - 1);
			g[v - 1].insert(u - 1);
		}
	}

	backtrack(0);

	return 0;
}