#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
	while(true) {
		int64_t a, b;
		cin >> a >> b;
		if(a == 0 && b == 0) break;

		cout << a / b << " " << a % b << " / " << b << endl;
	}
	return 0;
}