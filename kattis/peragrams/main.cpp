#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
	vector<int> cs(26);
	string s;
	cin >> s;

	for(const char& ch : s) {
		cs[ch - 'a']++;
	}

	int ans = 0;
	for(int i = 0; i < 26; i++) {
		ans += cs[i] % 2;
	}

	cout << max(0, ans - 1) << endl;

	return 0;
}