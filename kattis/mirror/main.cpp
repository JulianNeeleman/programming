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

	for(int t = 1; t <= T; t++) {
		int R, C;
		cin >> R >> C;
		
		vector<vector<char> > b(R, vector<char>(C));
		for(int i = 0; i < R; i++) {
			for(int j = 0; j < C; j++) {
				cin >> b[i][j];
			}
		}

		cout << "Test " << t << endl;
		for(int i = R - 1; i >= 0; i--) {
			for(int j = C - 1; j >= 0; j--) {
				cout << b[i][j];
			}
			cout << endl;
		}
	}

	return 0;
}