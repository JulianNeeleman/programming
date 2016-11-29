#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <iomanip>

using namespace std;

const double epsilon = 0.00000001;

struct Point {
	double x, y;
};

double solve(double D, double d) {
	double c = (D - d) / 2.0,
		base = (D / 2.0) * (D / 2.0) * D * M_PI,
		res = 2 * M_PI * (D * D * c / 4 - D * c * c / 2 + c * c * c / 3) + 
			M_PI * d * d * d / 4;
	return base - res;
}

int main() {
	while(true) {
		double D, V;
		cin >> D >> V;
		if(D == 0 && V == 0) break;

		double low = 0.0, high = D;
		while(high - low > epsilon) {
			double d = (low + high) / 2.0,
				res = solve(D, d);
			res < V ? high = d : low = d;
		}

		cout << setprecision(20) << low << endl;
	}

	return 0;
}