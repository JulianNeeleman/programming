#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <cmath>

using namespace std;

string S, P, C;

int main() {

	while(true) {
		int x;
		cin >> x;
		if(x == 0) break;
		cin >> S >> P >> C;
		int n = C.size();
	
		vector<char> M(n);

		int d = (int)floor(pow((double)n, 1.5) + x) % n;
		M[d] = P[find(S.begin(), S.end(), C[d]) - S.begin()];

		for(int i = (d - 1 + n) % n; i != d; i = (i - 1 + n) % n) {
			int j = find(S.begin(), S.end(), C[i]) - S.begin(),
				k = find(S.begin(), S.end(), M[(i + 1) % n]) - S.begin();
			M[i] = P[j ^ k];
		}

		for(const char& ch : M) cout << ch;
		cout << endl;
	}

	return 0;
}