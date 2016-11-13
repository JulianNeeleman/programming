#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <cmath>

using namespace std;

const double epsilon = 0.0001; 

struct Point {
	double x, y;
};

double dist(const Point& p, const Point& q) {
	return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
}

int check(const vector<Point>& ws, const vector<Point>& cs, double r) {
	for(const Point &p : ws) {
		bool success = false;
		for(const Point &q : cs) {
			if(dist(p, q) <= r + epsilon) success = true;
		}
		if(!success) return 5;
	}
	return cs.size();
}

int main() {
	double l, w, n, r;
	cin >> l >> w >> n >> r;
	vector<Point> ws = { { -l / 2.0, 0.0 }, { l / 2.0, 0.0 },
		{ 0.0, -w / 2.0 }, { 0.0, w / 2.0 } };

	vector<Point> cs(n);
	for(int i = 0; i < n; i++) {
		cin >> cs[i].x >> cs[i].y; 
	}

	int ans = 5;

	vector<Point> cur;
	for(int a = 0; a < n; a++) {
		cur.push_back(cs[a]);
		ans = min(ans, check(ws, cur, r));
		for(int b = a + 1; b < n; b++) {
			cur.push_back(cs[b]);
			ans = min(ans, check(ws, cur, r));
			for(int c = b + 1; c < n; c++) {
				cur.push_back(cs[c]);
				ans = min(ans, check(ws, cur, r));
				for(int d = c + 1; d < n; d++) {
					cur.push_back(cs[d]);	
					ans = min(ans, check(ws, cur, r));
					cur.pop_back();
				}
				cur.pop_back();
			}
			cur.pop_back();
		}
		cur.pop_back();
	}

	if(ans < 5) cout << ans << endl;
	else cout << "Impossible" << endl;

	return 0;
}