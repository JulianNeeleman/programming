#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
	int n, T;
	cin >> n >> T;

	int t = 0;
	for(int i = 0; i < n; i++) {
		int v;
		cin >> v;
		if(t + v > T) {
			cout << i << endl;
			return 0;
		}
		t += v;
	}

	cout << n << endl;

	return 0;
}