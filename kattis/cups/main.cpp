#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <sstream>

using namespace std;

int main() {
	int N;
	cin >> N;
	cin.ignore(256, '\n');

	vector<pair<int, string> > ps(N);

	for(int i = 0; i < N; i++) {
		string buffer;
		getline(cin, buffer);
		stringstream ss(buffer);

		if(buffer[0] >= '0' && buffer[0] <= '9') {
			ss >> ps[i].first >> ps[i].second;
		} else {
			ss >> ps[i].second >> ps[i].first;
			ps[i].first *= 2;
		}
	}

	sort(ps.begin(), ps.end());

	for(const pair<int, string>& p : ps) {
		cout << p.second << endl;
	}

	return 0;
}