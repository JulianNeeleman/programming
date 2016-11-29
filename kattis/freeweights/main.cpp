#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

bool solve(const vector<int>& t, const vector<int>& b, int m, int n) {
	vector<int> nt(1, -1), nb(1, -1);

	for(int i = 0; i < n; i++) {
		if(t[i] > m) nt.push_back(t[i]);
		if(b[i] > m) nb.push_back(b[i]);
	}

	nt.push_back(-1);
	nb.push_back(-1);

	for(int i = 1; i < nt.size() - 1; i++) {
		if(nt[i] != nt[i - 1] && nt[i] != nt[i + 1]) return false;
	}

	for(int i = 1; i < nb.size() - 1; i++) {
		if(nb[i] != nb[i - 1] && nb[i] != nb[i + 1]) return false;
	}

	return true;
}

int main() {
	int n;
	cin >> n;

	vector<int> t(n), b(n);
	for(int i = 0; i < n; i++) cin >> t[i];
	for(int i = 0; i < n; i++) cin >> b[i];

	int low = 0, high = 1000000000;
	while(high - low > 1) {
		int m = (low + high) / 2;
		solve(t, b, m, n) ? high = m : low = m;
	}

	cout << (solve(t, b, low, n) ? low : low + 1) << endl;

	return 0;
}