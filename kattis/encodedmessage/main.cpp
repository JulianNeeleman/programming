#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	while(N--) {
		string s;
		cin >> s;

		int root = round(sqrt((double)s.size()));

		vector<vector<char> > m(root, vector<char>(root));
		for(int i = 0; i < root; i++) for(int j = 0; j < root; j++) {
			m[i][j] = s[i * root + j];
		}

		string ans = "";
		for(int j = 0; j < root; j++) for(int i = root - 1; i >= 0; i--) {
			ans += m[i][j];
		}
		reverse(ans.begin(), ans.end());
		cout << ans << endl;
	}

	return 0;
}