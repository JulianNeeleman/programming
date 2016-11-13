#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int k, n, e;
vector<vector<int> > g;

int main() {
	while(true) {
		string ans = "Yes";
		cin >> k >> n >> e;
		if(k == 0) break;

		g.assign(1 << n, vector<int>());
		for(int i = 0; i < e; i++) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u); 
		}

		vector<double> dp(1 << n, 1.0 / (double)(1 << n));
		for(int i = 0; i < k; i++) {
			vector<double> bits(n), new_dp(1 << n);
			for(int j = 0; j < (1 << n); j++) {
				for(const int& v : g[j]) new_dp[v] += (double)dp[j] / (double)g[j].size();
				for(int d = 0; d < n; d++) {
					bits[d] += dp[j] * (double)((j >> d) & 1);
				}
			}
			for(const double& bit : bits) if(bit < 0.25 || bit > 0.75) ans = "No";
			dp = new_dp;
		}

		cout << ans << endl;
	}

	return 0;
}