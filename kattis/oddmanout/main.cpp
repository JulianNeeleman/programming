#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	for(int t = 1; t <= N; t++) {
		int G;
		cin >> G;
		
		vector<int64_t> gs(G + 2, -1);
		for(int i = 1; i <= G; i++) cin >> gs[i];
		sort(gs.begin(), gs.end());

		int64_t ans = 0;
		for(int i = 2; i <= G + 1; i++) {
			if(gs[i - 1] != gs[i] && gs[i + 1] != gs[i]) {
				ans = gs[i];
			}
		}

		cout << "Case #" << t << ": " << ans << endl;
	}

	return 0;
}