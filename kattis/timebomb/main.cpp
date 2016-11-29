#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

vector<string> digs = {"***   * *** *** * * *** *** *** *** ***",
				"* *   *   *   * * * *   *     * * * * *",
				"* *   * *** *** *** *** ***   * *** ***",
				"* *   * *     *   *   * * *   * * *   *",
				"***   * *** ***   * *** ***   * *** ***"};

map<vector<vector<char> >, int> ts;

void build() {
	for(int k = 0; k < 10; k++) {
		vector<vector<char> > res(5, vector<char>(3));
		for(int i = 0; i < 5; i++) {
			for(int j = 0; j < 3; j++) {
				res[i][j] = digs[i][j + 4 * k];
			}
		}
		ts[res] = k;
	}
}

int decode(const vector<vector<char> >& ds, int k) {
	vector<vector<char> > res(5, vector<char>(3));
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 3; j++) {
			res[i][j] = ds[i][j + k];
		}
	}
	if(ts.find(res) != ts.end()) return ts[res];
	return -1;
}

int main() {
	build();
	vector<vector<char> > ds(5);
	for(int i = 0; i < 5; i++) {
		string line;
		getline(cin, line);
		for(const char& ch : line) ds[i].push_back(ch);
	}

	int n = (ds[0].size() + 1) / 4, ans = 0, mul = 1;
	for(int i = n - 1; i >= 0; i--) {
		int d = decode(ds, 4 * i);
		if(d == -1) {
			cout << "BOOM!!" << endl;
			return 0;
		}
		ans += mul * d;
		mul *= 10;
	}

	cout << (ans % 6 != 0 ? "BOOM!!" : "BEER!!") << endl; 

	return 0;
}