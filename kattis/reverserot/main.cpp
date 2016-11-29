#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

const string ab = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";
const int n = ab.size();

int main() {

	map<char, char> m;
	for(int i = 0; i < n; i++) {
		m[ab[i]] = ab[(i + 1) % n];
	}

	while(true) {
		int N;
		cin >> N;
		if(N == 0) break;

		string s;
		cin >> s;
		reverse(s.begin(), s.end());

		for(int i = 0; i < N; i++) {
			for(char& ch : s) {
				ch = m[ch];
			}
		}

		cout << s << endl;
	}	


	return 0;
}