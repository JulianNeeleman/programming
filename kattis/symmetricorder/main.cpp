#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
	int T = 1;
	while(true) {
		int n;
		cin >> n;
		if(n == 0) break;

		vector<string> ans(n);
		for(int i = 0; i < n; i++) {
			cin >> ans[i % 2 == 0 ? i / 2 : n - 1 - i / 2]; 
		}

		cout << "SET " << T << endl;
		for(int i = 0; i < n; i++) {
			cout << ans[i] << endl;
		}
		T++;
	}

	return 0;
}