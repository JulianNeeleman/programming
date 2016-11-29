#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	for(int n = 1; n <= N; n++) {
		int S;
		cin >> S;

		vector<int> rs, bs;
		for(int i = 0; i < S; i++) {
			int v;
			char c;
			cin >> v >> c;
			(c == 'R' ? rs : bs).push_back(v);
		}

		sort(rs.begin(), rs.end());
		sort(bs.begin(), bs.end());
		int m = min(rs.size(), bs.size()),
			ans = 0;

		for(int i = rs.size() - m; i < rs.size(); i++) ans += rs[i] - 1;
		for(int i = bs.size() - m; i < bs.size(); i++) ans += bs[i] - 1;			
	
		cout << "Case #" << n << ": " << ans << endl;
	}

	return 0;
}