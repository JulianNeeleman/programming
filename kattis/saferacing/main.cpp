#include <iostream>
#include <vector>

using namespace std;

int64_t M = 123456789, L, S;

int64_t get(const vector<int64_t> &t, int i) {
	return i < 2 ? -1LL : t[i];
}

int main() {
	cin >> L >> S;
	vector<int64_t> DP(L + 1, 1), PS(L + 1, 1);
	DP[2] = 1, PS[2] = 1;

	for(int i = 3; i <= L; i++) {
		DP[i] = (PS[i - 1] - get(PS, i - S)) % M;
		PS[i] = (PS[i - 1] + DP[i]) % M;
	}

	for(int i = 0; i <= L; i++) cout << i << " " << DP[i] << " " << PS[i] << endl;

	int64_t ans = 0;
	for(int i = L - S + 1; i <= L; i++) {
		ans += (DP[i] * (L - i + 1)) % M;
	}

	cout << ans << endl;

	return 0;
}