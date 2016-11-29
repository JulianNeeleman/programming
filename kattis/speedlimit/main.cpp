#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
	while(true) {
		int n;
		cin >> n;
		if(n == -1) break;

		int ans = 0, last = 0;
		for(int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;

			ans += a * (b - last);
			last = b;
		}

		cout << ans << " miles" << endl;
	}

	return 0;
}