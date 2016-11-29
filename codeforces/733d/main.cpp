#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

struct Stone {
	vector<int> dims;
	int i;

	bool operator<(const Stone &rhs) const {
		return dims < rhs.dims;
	}
};

int main() {
	int n;
	cin >> n;

	vector<Stone> ss(n);
	for(int i = 0; i < n; i++) {
		ss[i].dims = vector<int>(3);
		ss[i].i = i + 1;
		cin >> ss[i].dims[0] >> ss[i].dims[1] >> ss[i].dims[2];
		sort(ss[i].dims.begin(), ss[i].dims.end());
		reverse(ss[i].dims.begin(), ss[i].dims.end());
	}

	sort(ss.begin(), ss.end());

	double ans = 0; 
	vector<int> res;
	for(int i = 0; i < n; i++) {
		double sphere = (double)ss[i].dims[2] / 2.0;
		if(ans < sphere) {
			ans = sphere;
			res = { ss[i].i };
		}
		if(i == n - 1) break;
		if(ss[i].dims[0] == ss[i + 1].dims[0] &&
			ss[i].dims[1] == ss[i + 1].dims[1]) {
			double sphere = ((double)ss[i].dims[2] + (double)ss[i + 1].dims[2]) / 2.0;
			sphere = min(sphere, (double)ss[i].dims[0] / 2.0);
			sphere = min(sphere, (double)ss[i].dims[1] / 2.0);
			if(ans < sphere) {
				ans = sphere;
				res = { ss[i].i, ss[i + 1].i };
			}
		}
	}

	cout << res.size() << endl;
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;

	return 0;
}