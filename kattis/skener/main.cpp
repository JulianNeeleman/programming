#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
	int R, C, Zr, Zc;
	cin >> R >> C >> Zr >> Zc;

	vector<vector<char> > m(R, vector<char>(C));
	for(int i = 0; i < R; i++) for(int j = 0; j < C; j++) {
		cin >> m[i][j];
	}

	for(int i = 0; i < R; i++) {
		for(int a = 0; a < Zr; a++) {
			for(int j = 0; j < C; j++) {
				for(int b = 0; b < Zc; b++) {
					cout << m[i][j];
				}
			}
			cout << endl;
		}
	}
	cout << endl;

	return 0;
}