#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {

	while(true) {
		int n;
		cin >> n;
		if(n == 0) break;

		vector<int> as(n), bs(n);
		for(int i = 0; i < n; i++) cin >> as[i];
		for(int i = 0; i < n; i++) cin >> bs[i];

		vector<int> cas(as.begin(), as.end());
		sort(cas.begin(), cas.end());
		sort(bs.begin(), bs.end());

		map<int, int> perm;
		for(int i = 0; i < n; i++) perm[cas[i]] = i; 
		for(int i = 0; i < n; i++) cout << bs[perm[as[i]]] << endl;
		cout << endl;
	}

	return 0;
}