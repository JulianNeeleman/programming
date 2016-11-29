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

	vector<string> ws(N);
	for(int i = 0; i < N; i++) cin >> ws[i];

	vector<string> cp(ws.begin(), ws.end());
	sort(cp.begin(), cp.end());

	bool inc = true;
	for(int i = 0; i < N && inc; i++) {
		if(ws[i] != cp[i]) inc = false;
	}

	if(inc) {
		cout << "INCREASING" << endl;
		return 0;
	}

	reverse(cp.begin(), cp.end());

	bool dec = true;
	for(int i = 0; i < N && dec; i++) {
		if(ws[i] != cp[i]) dec = false;
	}

	if(dec) {
		cout << "DECREASING" << endl;
		return 0;
	}

	cout << "NEITHER" << endl;

	return 0;
}