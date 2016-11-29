#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

const string cmp = "#welcome to code jam";

int main() {
	int T;
	cin >> T;
	cin.ignore(256, '\n');

	for(int t = 1; t <= T; t++) {
		string line;
		getline(cin, line);
		vector<int> DP(100);
		DP[0] = 1;

		for(const char& ch : line) {
			for(int i = cmp.size() - 1; i >= 0; i--) {
				if(ch == cmp[i]) DP[i] = (DP[i] + DP[i - 1]) % 10000;
			}
		}

		cout << "Case #" << t << ": ";
		if(DP[19] < 1000) cout << "0";
		if(DP[19] < 100) cout << "0";
		if(DP[19] < 10) cout << "0";
		cout << DP[19] << endl; 
	}

	return 0;
}