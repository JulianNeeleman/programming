#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
	string line;
	int n = 0;

	vector<int> ms;
	while(getline(cin, line)) {
		//cin.ignore(256, '\n');
		int m = line.size();
		n = max(n, m);
		ms.push_back(m);
	}

	int ans = 0;

	for(int i = 0; i < ms.size() - 1; i++) {
		ans += (n - ms[i]) * (n - ms[i]);
	}

	cout << ans << endl;

	return 0;
}