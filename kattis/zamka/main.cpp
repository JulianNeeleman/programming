#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int dig_sum(int n) {
	int res = 0;
	while(n > 0) {
		res += n % 10;
		n /= 10;
	}
	return res;
}

int main() {
	int L, D, X;
	cin >> L >> D >> X;

	int minv = -1, maxv = -1;
	for(int i = L; i <= D; i++) {
		int a = dig_sum(i);
		if(a == X) {
			if(minv == -1) minv = i;
			maxv = i;
		}
	}

	cout << minv << endl << maxv << endl;

	return 0;
}