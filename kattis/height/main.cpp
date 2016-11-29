#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
	int P;
	cin >> P;

	for(int i = 0; i < P; i++) {
		int K;
		cin >> K;
		cout << K;

		set<int> hs;
		int ans = 0;
		for(int j = 0; j < 20; j++) {
			int h;
			cin >> h;
			ans += distance(hs.insert(h).first, hs.end()) - 1;
		}
		cout << " " << ans << endl;
	}

	return 0;
}