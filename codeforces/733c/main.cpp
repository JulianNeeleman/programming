#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

vector<pair<int, char> > solve(vector<int> &as, int add) {
	int best = 0, pos = -1;
	for(size_t i = 0; i < as.size(); i++) {
		best = max(best, as[i]);
		if(best <= as[i] && ((i > 0 && as[i - 1] < as[i]) ||
			(i < as.size() - 1 && as[i + 1] < as[i]))) pos = i;
	}
	if(pos == -1) return vector<pair<int, char> >();
	
	vector<pair<int, char> > res;
	int a = pos, b = pos, acc = as[pos];
	for(int i = 0; i < as.size() - 1; i++) {
		if(a > 0 && as[a - 1] < acc) {
			acc += as[a - 1];
			a--;
			res.push_back({a + add + 1, 'L'});
		} else if (b < as.size() - 1 && as[b + 1] < acc) {
			acc += as[b + 1];
			b++;
			res.push_back({a + add, 'R'});
		} else {
			return vector<pair<int, char> >();
		}
	}
	return res;
}

int main() {
	int n;
	cin >> n;

	vector<int> as(n);
	for(int i = 0; i < n; i++) {
		cin >> as[i];
	}

	int k;
	cin >> k;

	vector<int> bs(k);
	for(int i = 0; i < k; i++) {
		cin >> bs[i];
	}

	int acc = 0;
	vector<pair<int, char> > ans;
	int j = 0;
	for(int i = 0; i < k; i++) {
		int from = j;
		while(acc < bs[i] && j < n) {
			acc += as[j], j++;
		}
		if(acc != bs[i]) {
			cout << "NO" << endl;
			return 0;
		}
		vector<int> slice(as.begin() + from, as.begin() + j);
		vector<pair<int, char> > part = solve(slice, i + 1);
		if(part.empty() && j - from > 1) {
			cout << "NO" << endl;
			return 0;
		}
		ans.insert(ans.end(), part.begin(), part.end());
		acc = 0;
	}

	if(j != n) {
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;
	for(const pair<int, char> &p : ans) {
		cout << p.first << " " << p.second << endl;
	}

	return 0;
}