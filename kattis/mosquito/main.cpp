#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
	int M, P, L, E, R, S, N;
	while(cin >> M >> P >> L >> E >> R >> S >> N) {
		for(int i = 0; i < N; i++) {
			int nM = P / S,
				nP = L / R,
				nL = M * E;
			M = nM, P = nP, L = nL;
		}

		cout << M << endl;
	}
	return 0;
}