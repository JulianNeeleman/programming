#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> cs(N + M + 1);
	int ans = 0;

	for(int n = 1; n <= N; n++) {
		for(int m = 1; m <= M; m++) {
			cs[n + m]++;
			ans = max(ans, cs[n + m]);
		}
	}

	for(int i = 0; i <= N + M; i++) {
		if(cs[i] == ans) cout << i << endl;
	}

	return 0;
}