#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
	int64_t n, a, b, c;
	cin >> n >> a >> b >> c;

	if(n % 4 == 0) cout << 0 << endl;
	else if(n % 4 == 3) cout << min(a, min(b + c, 3 * c)) << endl;
	else if(n % 4 == 2) cout << min(2 * a, min(b, 2 * c)) << endl;
	else {
		cout << min(3 * a, min(a + b, c)) << endl;
	}

	return 0;
}