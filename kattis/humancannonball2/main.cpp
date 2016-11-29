#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	while(N--) {
		double v0, theta, x1, h1, h2;
		cin >> v0 >> theta >> x1 >> h1 >> h2;
		
		theta *= M_PI / 180.0;
		double t = x1 / (v0 * cos(theta)),
			h = v0 * t * sin(theta) - 0.5 * 9.81 * t * t;

		cout << (h > h1 + 1 && h < h2 - 1 ? "Safe" : "Not Safe") << endl;  
	}

	return 0;
}