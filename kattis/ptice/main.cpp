#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	string S;
	cin >> S;

	int a = 0, b = 0, c = 0;
	vector<char> A(N), B(N), C(N);
	for(int i = 0; i < N; i++) {
		switch(i % 3) {
			case 0: A[i] = 'A'; break;
			case 1: A[i] = 'B'; break;
			case 2: A[i] = 'C'; break;
		}
		switch(i % 4) {
			case 0: B[i] = 'B'; break;
			case 1: B[i] = 'A'; break;
			case 2: B[i] = 'B'; break;
			case 3: B[i] = 'C'; break;
		}
		switch(i % 6) {
			case 0: C[i] = 'C'; break;
			case 1: C[i] = 'C'; break;
			case 2: C[i] = 'A'; break;
			case 3: C[i] = 'A'; break;
			case 4: C[i] = 'B'; break;
			case 5: C[i] = 'B'; break;
		}

		a += A[i] == S[i];
		b += B[i] == S[i];
		c += C[i] == S[i];
	}

	int ans = max(a, max(b, c));
	cout << ans << endl;
	if(a == ans) cout << "Adrian" << endl;
	if(b == ans) cout << "Bruno" << endl;
	if(c == ans) cout << "Goran" << endl; 

	return 0;
}