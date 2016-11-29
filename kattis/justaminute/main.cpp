#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <iomanip>

using namespace std;

const double epsilon = 0.000000001;

int main() {
	int N;
	cin >> N;

	double ans = 0.0, cm = 0.0;
	for(int i = 0; i < N; i++) {
		double M, S;
		cin >> M >> S;
		ans += M * (S / (M * 60.0));
		cm += M;
	}

	if(ans / cm <= 1.0 + epsilon) cout << "measurement error" << endl;
	else cout << setprecision(20) << ans / cm << endl;

	return 0;
}