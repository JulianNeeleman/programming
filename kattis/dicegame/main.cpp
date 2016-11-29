#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
	vector<int> g(4), e(4);
	for(int i = 0; i < 4; i++) cin >> g[i];
	for(int i = 0; i < 4; i++) cin >> e[i];

	int ans = 0;
	for(int i = g[0]; i <= g[1]; i++) {
		for(int j = g[2]; j <= g[3]; j++) {
			int gs = i + j;
			for(int k = e[0]; k <= e[1]; k++) {
				for(int l = e[2]; l <= e[3]; l++) {
					int es = k + l;
					if(gs < es) ans--;
					else if(gs > es) ans++;
				}
			}
		}
	}

	if(ans < 0) cout << "Emma" << endl;
	else if(ans > 0) cout << "Gunnar" << endl;
	else cout << "Tie" << endl;
}