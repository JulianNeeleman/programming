#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
	int K;
	cin >> K;

	int a = 1, b = 0;
	for(int i = 0; i < K; i++) {
		int tmp = a;
		a = b;
		b += tmp;
	}

	cout << a << " " << b << endl;

	return 0;
}