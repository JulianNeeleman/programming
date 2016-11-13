#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <iomanip>
#include <climits>

using namespace std;

const double epsilon = 0.00000001;

struct Point {
	double x, y;

	bool operator<(const Point& rhs) const {
		return x == rhs.x ? y < rhs.y : x < rhs.x;
	}

	void operator-=(const Point& rhs) {
		this->x -= rhs.x, this->y -= rhs.y;
	}
};

Point operator-(const Point& lhs, const Point& rhs) {
	return { lhs.x - rhs.x, lhs.y - rhs.y };
}

Point operator+(const Point& lhs, const Point& rhs) {
	return { lhs.x + rhs.x, lhs.y + rhs.y };
}

Point operator*(const double& scalar, const Point& p) {
	return { scalar * p.x, scalar * p.y };
}

double polygon_area(const vector<Point> &poly) {
    double area = 0.0;
    int n = poly.size(),
        j = n - 1;

    for(int i = 0; i < n; i++) {
        area += (poly[j].x + poly[i].x) * (poly[j].y - poly[i].y);
        j = i;
    }

    return abs(area / 2.0);
}

double cross(const Point& p, const Point& q) {
	return p.x * q.y - p.y * q.x;
}

double dot(const Point& p, const Point& q) {
	return p.x * q.x + p.y * q.y;
}

vector<Point> intersects(const Point& p, const Point& q, Point r, Point s) {
	r -= p, s -= q;
	double cqps = cross(q - p, s),
		crs = cross(r, s);

	if(cqps < epsilon && crs < epsilon) {
		double rr = dot(r, r),
			t0 = dot(q - p, r) / rr,
			t1 = t0 + dot(s, r) / rr;
		return { p + t0 * r, p + t1 * r };
	} else {
		double t = cqps / crs,
			u = cross(q - p, r) / crs;
		if(crs < epsilon) {
			return vector<Point>();
		} else if(0 <= t && t <= 1 && 0 <= u && u <= 1) {
			return { p + t * r };
		} else return vector<Point>();
	}
}

pair<Point, int> scan(const vector<Point>& alpha, double X) {
	int low = 0, high = alpha.size() - 2;
	while(true) {
		int mid = (low + high) / 2.0,
			min_x = min(alpha[mid].x, alpha[mid + 1].x),
			max_x = max(alpha[mid].x, alpha[mid + 1].x);
		if(X < min_x) min_x == alpha[mid].x ? high = mid : low = mid;
		else if(X > max_x) min_x == alpha[mid].x ? low = mid : high = mid;
		else { 
			low = mid;
			break;
		};
	}

	double min_y = min(alpha[low].y, alpha[low + 1].y) - 1.0,
		max_y = max(alpha[low].y, alpha[low + 1].y) + 1.0;

	vector<Point> ps = intersects(alpha[low], { X, min_y },
		alpha[low + 1], { X, max_y });


	return { ps[0], low };
}

double check(const vector<Point>& alpha, const vector<Point>& beta, double X) {
	pair<Point, int> p = scan(alpha, X),
		q = scan(beta, X);

	vector<Point> ps(alpha.begin(), alpha.begin() + p.second + 1);
	ps.push_back(p.first);
	ps.push_back(q.first);
	vector<Point> rbeta(beta.begin(), beta.begin() + q.second + 1);
	reverse(rbeta.begin(), rbeta.end());
	ps.insert(ps.end(), rbeta.begin(), rbeta.end() - 1);

	return polygon_area(ps);
}

int main() {
	int N;
	double C;
	cin >> C >> N;

	vector<Point> ps(N);
	double min_x = INT_MAX, min_i = 0,
		max_x = INT_MIN, max_i = 0;
	for(int i = 0; i < N; i++) {
		cin >> ps[i].x >> ps[i].y;
		if(ps[i].x < min_x) min_x = ps[i].x, min_i = i;
		if(ps[i].x > max_x) max_x = ps[i].x, max_i = i;
	}

	int a = min(min_i, max_i),
		b = max(min_i, max_i);

	vector<Point> alpha(ps.begin() + a, ps.begin() + b + 1),
		beta(ps.begin() + b, ps.end());
	reverse(alpha.begin(), alpha.end());
	beta.insert(beta.end(), ps.begin(), ps.begin() + a + 1);

	double area = polygon_area(ps);
	int M = floor(area / C);
	double section = area / M;
	cout << section << endl;

	cout << M << endl;
	for(int i = 1; i < M; i++) {
		double t = (double)i * section,
			low = min_x, high = max_x;
		while(high - low > epsilon) {
			double mid = (low + high) / 2.0,
				ch = check(alpha, beta, mid),
				error = t - ch;
			cout << t << " " << ch << endl;
			error < 0 ? high = mid : low = mid;
		}
		cout << low << endl;
	} 

	return 0;
}