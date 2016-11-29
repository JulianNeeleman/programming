#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
	int h, m;
	cin >> h >> m;

	for(int i = 0; i < 45; i++) {
		m--;
		if(m == -1) m = 59, h--;
		if(h == -1) h = 23;
	}

	cout << h << " " << m << endl;

	return 0;
}