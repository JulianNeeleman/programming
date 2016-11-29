#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

map<char, int> m = { {'A', 11}, {'K', 4}, {'Q', 3},
	{'J', 2}, {'T', 10}, {'9', 0}, {'8', 0}, {'7', 0} };

int main() {
	int N;
	char B;
	cin >> N >> B;

	int ans = 0;
	for(int i = 0; i < 4 * N; i++) {
		char n, s;
		cin >> n >> s;
		ans += m[n];
		if(s == B && n == 'J') ans += 18;
		if(s == B && n == '9') ans += 14;
	}

	cout << ans << endl;

	return 0;
}