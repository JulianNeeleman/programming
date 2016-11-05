#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

struct Point {
	int x, y;
};

const int N = 8;
int i = N, j = N, alive = N * N, ans = 0;
vector<vector<bool> > board(3 * N, vector<bool>(3 * N));
vector<vector<int> > kills(3 * N, vector<int>(3 * N));
vector<Point> ps;

int64_t its = 0;

void next() {
	j < 2 * N - 1 ? j++ : (i++, j = N);
}

void prev() {
	j > N ? j-- : (i--, j = 2 * N - 1);
}

void kill(const Point &p, const Point &q, int v) {
	Point r = { p.x + q.x + q.y - p.y,
		p.y + q.y + p.x - q.x },
		s = { p.x + q.x + p.y - q.y,
			p.y + q.y + q.x - p.x };
	if((r.x % 2) + (r.y % 2) + (s.x % 2) + (s.y % 2) > 0) return;
	r.x /= 2, r.y /= 2, s.x /= 2, s.y /= 2;
	if(board[r.x][r.y]) {
		kills[s.x][s.y] += v;
		if((kills[s.x][s.y] == (v > 0)) && 
			s.x >= N && s.x < 2 * N && s.y >= N && s.x < 2 * N &&
			(s.y > i || (s.y == i && s.x > j))) alive -= v;
	} else if(board[s.x][s.y]) {
		kills[r.x][r.y] += v;
		if((kills[r.x][r.y] == (v > 0)) &&
			r.x >= N && r.x < 2 * N && r.y >= N && r.x < 2 * N &&
			(r.y > i || (r.y == i && r.x > j))) alive -= v;
	}
} 

void print() {
	for(int i = N; i < 2 * N; i++) {
		for(int j = N; j < 2 * N; j++) {
			cout << board[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void rec() {
	its++;
	if(ps.size() + alive <= ans) return;
	if(i >= 3 * N / 2 && j >= (N % 2) * (N / 2) && ps.size() <= ans / 2) return;

	if(i == 2 * N) {
		if(ps.size() > ans) {
			ans = ps.size();
			cout << ans << endl;
			print();
		}
		return;
	}

	if(kills[i][j] == 0) {
		board[i][j] = true;
		for(const Point &p : ps) kill(p, {i, j}, 1);
		ps.push_back({i, j});
		next();
		alive--;
		rec();
		alive++;
		prev();
		ps.pop_back();	
		for(const Point &p : ps) kill(p, {i, j}, -1);
		board[i][j] = false;
	}

	if(kills[i][j] == 0) alive--;
	next();
	rec();
	prev();
	if(kills[i][j] == 0) alive++;

}

int main() {
	rec();
	cout << "Maximum pawns: " << ans << " (" << its << " states checked)" << endl;
	return 0;
}