#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <climits>

using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		int minv = INT_MAX, maxv = -INT_MAX;
		for(int i = 0; i < n; i++) {
			int v;
			cin >> v;
			minv = min(minv, v);
			maxv = max(maxv, v);
		}
		
		int ans = INT_MAX;
		for(int i = 0; i < 100; i++) {
			ans = min(ans, 2 * abs(i - minv) + 2 * abs(i - maxv));
		}

		cout << ans << endl;
	}

	return 0;
}