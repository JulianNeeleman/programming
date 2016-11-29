#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	int L = 0, R = 0;
	vector<pair<int, int> > cs(n);
	for(int i = 0; i < n; i++) {
		cin >> cs[i].first >> cs[i].second;
		L += cs[i].first, R += cs[i].second;
	}

	int best = abs(L - R), col = 0;

	for(int i = 0; i < n; i++) {
		L -= cs[i].first, R -= cs[i].second;
		L += cs[i].second, R += cs[i].first;
		if(best < abs(L - R)) {
			best = abs(L - R), col = i + 1;
		}
		L += cs[i].first, R += cs[i].second;
		L -= cs[i].second, R -= cs[i].first; 
	}

	cout << col << endl;

	return 0;
}