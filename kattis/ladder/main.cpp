#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
	double h, v;
	cin >> h >> v;
	v /= 180 / M_PI;
	cout << ceil(h / sin(v)) << endl;

	return 0;
}