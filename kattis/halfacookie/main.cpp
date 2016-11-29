#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
	double r, x, y;
	while(cin >> r >> x >> y) {
		double d = sqrt(x * x + y * y);
		if(d > r) {
			cout << "miss" << endl;
			continue;
		}

		double area = M_PI * r * r,
			theta = 2 * acos(d / r) / (2.0 * M_PI),
			l = tan(theta * M_PI) * d,
			small = area * theta - l * d;

		cout << setprecision(20) << area - small << " " << small << endl;
	}

	return 0;
}