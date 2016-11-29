#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

const int M = 10000;

int main() {
	int P;
	cin >> P;

	vector<int> S1(M + 1), S2(M + 1), S3(M + 1);
	for(int i = 1; i <= 2 * M; i++) {
		if(i <= M) S1[i] = S1[i - 1] + i;

		if(i % 2) S2[(i + 1) / 2] = S2[i / 2] + i;
		else S3[i / 2] = S3[i / 2 - 1] + i;
	}

	for(int i = 1; i <= P; i++) {
		int K, N;
		cin >> K >> N;
		cout << K << " " << S1[N] << " " << S2[N] << " " << S3[N] << endl;
	}

	return 0;
}