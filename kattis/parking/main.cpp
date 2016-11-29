#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
	vector<int> ts(4);
	cin >> ts[1] >> ts[2] >> ts[3];

	vector<pair<int, bool> > es(6);

	for(int i = 0; i < 6; i++) {
		cin >> es[i].first;
		es[i].second = i % 2;
	}

	sort(es.begin(), es.end());

	int p = 0, last = 0, ans = 0;
	for(int i = 0; i < 6; i++) {
		ans += ts[p] * p * (es[i].first - last);
		es[i].second ? p-- : p++;
		last = es[i].first;
	}

	cout << ans << endl;

	return 0;
}