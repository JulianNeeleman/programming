#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
	int ans = 0;
	vector<bool> seen(42);
	for(int i = 0; i < 10; i++) {
		int a;
		cin >> a;
		if(!seen[a % 42]) ans++;
		seen[a % 42] = true;
	}

	cout << ans << endl;

	return 0;
}