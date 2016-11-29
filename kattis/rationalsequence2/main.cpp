#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

struct Rational {
	int64_t p, q;
};

int main() {
	int P;
	cin >> P;

	for(int t = 1; t <= P; t++) {
		Rational a;
		char c;
		cin >> a.p >> a.p >> c >> a.q;
		
		string path = "";
		while(a.p != 1 || a.q != 1) {
			if(a.p < a.q) {
				a.q -= a.p;
				path.push_back('L');
			} else {
				a.p -= a.q;
				path.push_back('R');
			}
		}

		reverse(path.begin(), path.end());
		
		int64_t ans = 1;
		for(const char& ch : path) {
			ans = 2 * ans + (ch == 'R');
		}

		cout << t << " " << ans << endl;
	}

	return 0;
}