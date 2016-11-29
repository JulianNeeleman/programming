#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

bool check(const vector<int>& as) {
	int d = as[1] - as[0],
		n = as.size();

	for(int i = 0; i < n - 1; i++) {
		if(as[i + 1] - as[i] != d) return false;
	}
	return true;
}

int main() {
	int n;
	cin >> n;

	while(n--) {
		int m;
		cin >> m;

		vector<int> as(m);
		for(int i = 0; i < m; i++) cin >> as[i];
		int d = as[1] - as[0];

		if(check(as)) cout << "arithmetic" << endl;
		else {
			sort(as.begin(), as.end());
			if(check(as)) cout << "permuted arithmetic" << endl;
			else cout << "non-arithmetic" << endl;
		}

	}
	return 0;
}