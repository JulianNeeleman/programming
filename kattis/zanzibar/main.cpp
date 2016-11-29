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
		int a, b = 1, ans = 0;
		while(true) {
			cin >> a;
			if(a == 0) break;
			ans += max(0, a - 2 * b); 
			b = a;
		}
		cout << ans << endl;
	}

	return 0;
}