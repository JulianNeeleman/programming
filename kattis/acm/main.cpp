#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
	map<char, int> ps;
	pair<int, int> ans = {0, 0};

	while(true) {
		int m;
		char p;
		string v;
		cin >> m;
		if(m == -1) break;
		cin >> p >> v;

		if(v == "right") {
			ans.first++;
			ans.second += m + ps[p]; 
		} else {
			ps[p] += 20;
		}
	}

	cout << ans.first << " " << ans.second << endl;

	return 0;
}