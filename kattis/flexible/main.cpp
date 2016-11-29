#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
	int W, P;
	cin >> W >> P;

	vector<int> ps(P + 2);
	ps[0] = 0, ps[P + 1] = W;
	for(int i = 1; i <= P; i++) cin >> ps[i];

	set<int> ans;
	for(int i = 0; i < P + 2; i++) {
		for(int j = i + 1; j < P + 2; j++) {
			ans.insert(ps[j] - ps[i]);
		}
	}

	for(const int& v : ans) cout << v << " ";
	cout << endl;

	return 0;
}