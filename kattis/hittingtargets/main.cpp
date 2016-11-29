#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

struct Rectangle {
	double x1, y1, x2, y2;
};

struct Circle {
	double x, y, r; 
};

const double epsilon = 0.00001;

int is(Rectangle r, double x, double y) {
	return x >= r.x1 && x <= r.x2 && y >= r.y1 && y <= r.y2;
}

int is(Circle c, double x, double y) {
	return sqrt((x - c.x) * (x - c.x) + (y - c.y) * (y - c.y)) < c.r + epsilon;
}

int main() {
	int m;
	cin >> m;

	vector<Rectangle> rs;
	vector<Circle> cs;

	for(int i = 0; i < m; i++) {
		string type;
		cin >> type;
		if(type == "rectangle") {
			Rectangle r;
			cin >> r.x1 >> r.y1 >> r.x2 >> r.y2;
			rs.push_back(r);
		} else {
			Circle c;
			cin >> c.x >> c.y >> c.r;
			cs.push_back(c);
		}
	}

	int n;
	cin >> n;

	for(int i = 0; i < n; i++) {
		double x, y;
		cin >> x >> y;

		int res = 0;
		for(const Rectangle& r : rs) res += is(r, x, y);
		for(const Circle& c : cs) res += is(c, x, y);
		cout << res << endl;
	}

	return 0;
}