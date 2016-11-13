#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <bitset>
#include <climits>

using namespace std;

const int K = 101;
bitset<K> check;

int main() {
	int B;
	cin >> B;

	int tot = 0;
	vector<pair<bitset<K>, int> > bs(B);
	for(int i = 0; i < B; i++) {
		cin >> bs[i].second;
		tot += bs[i].second;
	}

	int T;
	cin >> T;
	for(int i = 0; i < T; i++) {
		int M, b;
		cin >> M;
		for(int j = 0; j < M; j++) {
			cin >> b;
			bs[b - 1].first.set(i, true);
		}
		check.set(i, true);
	}

	int ans = 0;
	for(int i = 0; i < (1 << B); i++) {
		bitset<K> res;
		int bits = i, c = 0, j = 0;
		while(bits > 0) {
			if(bits & 1) {
				res |= bs[j].first;
				c += bs[j].second;
			}
			bits >>= 1;
			j++;
		}
		if(res == check) ans = max(ans, tot - c);
	}

	cout << ans << endl;

	return 0;
}