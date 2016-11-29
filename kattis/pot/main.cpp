#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
	int N, ans = 0;
	cin >> N;

	for(int i = 0; i < N; i++) {
		int P;
		cin >> P;

		int b = P / 10,
			e = P % 10;

		ans += pow(b, e);
	}

	cout << ans << endl;

	return 0;
}