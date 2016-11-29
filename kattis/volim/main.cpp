#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
	int K, N;
	cin >> K >> N;
	K--;

	int T = 0;
	for(int i = 0; i < N; i++) {
		int t;
		char v;
		cin >> t >> v;
		
		T += t;
		if(T > 210) break;

		if(v == 'T') K = (K + 1) % 8;
	}

	cout << K + 1 << endl;

	return 0;
}