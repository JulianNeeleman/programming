#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
	vector<int> ps(4);
	for(int i = 0; i < 4; i++) cin >> ps[i];
	sort(ps.begin(), ps.end());

	cout << ps[0] * ps[2] << endl;

	return 0;
}