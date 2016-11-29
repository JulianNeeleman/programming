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

	int mex = n;
	set<int> rs;
	for(int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		mex = min(mex, r - l + 1);
		rs.insert(r);
	}

	rs.insert(n);

	cout << mex << endl;

	for(int i = 1; i <= n; i++) {
		int d = *upper_bound(rs.begin(), rs.end(), i - 1);
		cout << d - i << " ";
	}
	cout << endl;

	return 0;
}