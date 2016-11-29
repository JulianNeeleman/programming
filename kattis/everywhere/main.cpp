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
		int n;
		cin >> n;

		set<string> seen;

		for(int i = 0; i < n; i++) {
			string s;
			cin >> s;
			seen.insert(s);
		}

		cout << seen.size() << endl;
	}

	return 0;
}