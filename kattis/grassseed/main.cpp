#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
	double C, w, l, ans = 0;
	int L;

	cin >> C >> L;
	for(int i = 0; i < L; i++) {
		cin >> w >> l;
		ans += w * l * C;
	}

	cout << setprecision(20) << ans << endl;

	return 0;
}