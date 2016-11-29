#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
	string s;
	cin >> s;

	int ans = 0;

	for(int i = 0; i < s.size(); i++) {
		switch(i % 3) {
			case 0: ans += (s[i] != 'P'); break;
			case 1: ans += (s[i] != 'E'); break;
			case 2: ans += (s[i] != 'R');
		}
	}

	cout << ans << endl;

	return 0;
}