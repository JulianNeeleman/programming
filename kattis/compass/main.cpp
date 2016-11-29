#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	for(int i = 0; i < 360; i++) {
		if((a + i) % 360 == b) {
			cout << i << endl;
			return 0;
		} else if((a - i + 360) % 360 == b) {
			cout << -i << endl;
			return 0;
		}
	}

	return 0;
}