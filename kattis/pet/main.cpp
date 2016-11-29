#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
	pair<int, int> ans = { 0, 0 };
	for(int i = 1; i <= 5; i++) {
		int s = 0;
		for(int i = 0; i < 4; i++) {
			int a;
			cin >> a;
			s += a;
		}
		if(s > ans.second) {
			ans.first = i;
			ans.second = s;
		}
	}

	cout << ans.first << " " << ans.second << endl;

	return 0;
}