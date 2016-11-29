#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <iomanip>

using namespace std;

int main() {

	while(true) {
		int a, b, s, m, n;
		cin >> a >> b >> s >> m >> n;
		if(a + b + s + m + n == 0) break;

		double hd = a * m,
			vd = b * n,
			d = sqrt(hd * hd + vd * vd),
			v = d / s,
			theta = atan(vd / hd) * 180.0 / M_PI;

		cout << setprecision(2) << fixed << theta << " " << v << endl;
	}

	return 0;
}