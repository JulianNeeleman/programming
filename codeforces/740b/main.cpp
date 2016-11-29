#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> as(n + 1), cm(n + 1);
	for(int i = 1; i <= n; i++) cin >> as[i];
	for(int i = 1; i <= n; i++) cm[i] = cm[i - 1] + as[i];

	int ans = 0;
	for(int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		ans += max(0, cm[r] - cm[l - 1]);
	}

	cout << ans << endl;

	return 0;
}