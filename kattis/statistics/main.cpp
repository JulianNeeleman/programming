#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <climits>

using namespace std;

int main() {
	int n;
	int t = 1;
	while(cin >> n) {
		int minv = INT_MAX, maxv = -INT_MAX;
		for(int i = 0; i < n; i++) {
			int v;
			cin >> v;
			minv = min(minv, v);
			maxv = max(maxv, v);
		}
		cout << "Case " << t << ": " << minv << " " << maxv << " " << (maxv - minv) << endl;
		t++;
	}
	return 0;
}