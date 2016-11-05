#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <cmath>

using namespace std;

const double epsilon = 0.00001;

struct Point {
	double x, y;
};

double dist(Point p, Point q) {
	return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
}

vector<Point> intersections(Point p, Point q, double pr, double qr) {
	double d = dist(p, q);
	if(pr + qr < d) return vector<Point>();
	if(min(pr, qr) + d + epsilon < max(pr, qr)) return vector<Point>();
	double a = (pr * pr - qr * qr + d * d) / (2.0 * d),
		h = sqrt(pr * pr - a * a);

	Point m = { p.x + (a * (q.x - p.x)) / d, 
		p.y + (a * (q.y - p.y)) / d },
		r = { m.x + (h * (q.y - p.y) / d),
			m.y - (h * (q.x - p.x)) / d },
		s = { m.x - (h * (q.y - p.y) / d),
			m.y + (h * (q.x - p.x)) / d };

	return {r, s};
}

double random_double(double dmin, double dmax) {
    double res = (double)rand() / RAND_MAX;
    return res * 1000.0;
}

vector<vector<double> > get_random_matrix(int N) {
	vector<Point> ps(N);
	for(int i = 0; i < N; i++) {
		ps[i].x = random_double(0.0, 100.0);
		ps[i].y = random_double(0.0, 100.0); 
	}

	vector<vector<double> > adj(N, vector<double>(N));
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) {
		adj[i][j] = dist(ps[i], ps[j]);
	}

	return adj;
}

int main() {
	srand(time(NULL));
	
	int N;
	cin >> N;

	vector<vector<double> > adj = get_random_matrix(N);

	//vector<vector<double> > adj(N, vector<double>(N));

	/*
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> adj[i][j];
		}
	}
	*/

	vector<Point> ps(N);

	for(int i = 0; i < N; i++) {
		if(i == 0) ps[i] = {0.0, 0.0};
		else if(i == 1) ps[i] = { adj[0][1], 0.0 };
		else if(i == 2) {
			vector<Point> is = intersections(ps[0], ps[1], adj[0][2], adj[1][2]);
			if(is.empty()) {
				cout << "Invalid" << endl;
				return 0;
			}
			ps[i] = is[0];
		} else {
			vector<Point> first = intersections(ps[0], ps[1], adj[0][i], adj[1][i]),
				second = intersections(ps[1], ps[2], adj[1][i], adj[2][i]);
			if(first.empty() || second.empty()) {
				cout << "Invalid" << endl;
				return 0;
			}
 			if(min(dist(first[0], second[0]), dist(first[0], second[1])) < epsilon) ps[i] = first[0];
			else if(min(dist(first[1], second[0]), dist(first[1], second[1])) < epsilon) ps[i] = first[1];
			else {
				cout << "Invalid" << endl;
				return 0;
			}
		}
	}

	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) {
		if(abs(dist(ps[i], ps[j]) - adj[i][j]) > epsilon) {
			cout << "Invalid" << endl;
			return 0;
		}
	}

	cout << "Valid" << endl;
	for(const Point &p : ps) {
		cout << p.x << " " << p.y << endl;
	}

	return 0;
}