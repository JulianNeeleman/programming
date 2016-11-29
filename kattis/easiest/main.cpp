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
	while(true) {
		int N;
		cin >> N;
		if(N == 0) break;
		
		int p = 11, ds = dig_sum(N);
		while(dig_sum(p * N) != ds) p++;
		cout << p << endl;
	}
	return 0;
}