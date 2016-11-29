#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
	int T;
	cin >> T;

	while(T--) {
		int D, M;
		cin >> D >> M;
		
		int acc = 0, ans = 0;
		for(int i = 0; i < M; i++) {
			int d;
			cin >> d;
			if(d >= 13 && (acc + 13) % 7 == 6) ans++;
			acc += d;
		}
		
		cout << ans << endl;
	}

	return 0;
}