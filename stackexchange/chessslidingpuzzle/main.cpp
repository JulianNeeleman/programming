#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <cstring>
#include <bitset>

using namespace std;

// Struct that defines ordering for map memoization
// Sort descending by position of lowest bit
struct ordering {
    bool operator()(const bitset<192>& lhs, const bitset<192>& rhs) const {
	    for(int i = 191; i >= 0; i--) {
	        if (lhs[i] ^ rhs[i]) return rhs[i];
	    }
	    return false;
	}
};


struct State {
	int i, j, m, pm;
	char board[12][12];

	bool operator<(const State& rhs) const {
		if(pm != rhs.pm) return pm < rhs.pm;
		for(int i = 2; i < 10; i++) {
			for(int j = 2; j < 10; j++) {
				if(board[i][j] != rhs.board[i][j]) {
					return board[i][j] < rhs.board[i][j];
				}
			}
		}
		return false;
	}

	bool operator>(const State& rhs) const {
		if(pm != rhs.pm) return pm > rhs.pm;
		for(int i = 2; i < 10; i++) {
			for(int j = 2; j < 10; j++) {
				if(board[i][j] != rhs.board[i][j]) {
					return board[i][j] < rhs.board[i][j];
				}
			}
		}
		return false;
	}
};

bitset<192> encode(const State& s) {
	bitset<192> res;
	for(int i = 2; i < 10; i++) {
		for(int j = 2; j < 10; j++) {
			int k = 3 * ((i - 2) * 8 + (j - 2));
			res.set(k    , s.board[i][j] == 'p' || s.board[i][j] == 'b' || s.board[i][j] == 'x');
			res.set(k + 1, s.board[i][j] == 'k' || s.board[i][j] == 'b');
			res.set(k + 2, s.board[i][j] == 'r' || s.board[i][j] == 'p');
		}
	}
	return res;
}

// Keep track of visited states to avoid multiple
// evaluations of the same configuration.
set<bitset<192>, ordering> mem;

// Initialize BFS queue.
priority_queue<State, vector<State>, greater<State> > q;

int64_t cache = 0;

void check(State& s, const char t, const int di, const int dj) {
	if(s.board[s.i + di][s.j + dj] == t) {
		swap(s.board[s.i][s.j], s.board[s.i + di][s.j + dj]);
		s.i += di, s.j += dj, s.m++;
		if(t == 'p') s.pm++;
		if(s.m <= 80 && mem.insert(encode(s)).second) q.push(s);
		else cache++;
		if(t == 'p') s.pm--;
		s.i -= di, s.j -= dj, s.m--;
		swap(s.board[s.i][s.j], s.board[s.i + di][s.j + dj]);
	}
}

int main() {
	// Declare state.
	State s;

	// Set moves to zero.
	s.m = 0, s.pm = 0;

	// Initialize board with all v's.
	memset(s.board, 'v', sizeof(s.board[0][0]) * 144);
	
	// Load configuration from standard input.
	for(int i = 2; i < 10; i++) {
		for(int j = 2; j < 10; j++) {
			cin >> s.board[i][j];
			if(s.board[i][j] == 'o') {
				s.i = i, s.j = j;
			}
		}
	}

	// Push initial state to queue.
	q.push(s);
	mem.insert(encode(s));

	int max_pm = 0;

	// Run BFS.
	State c;
	while(!q.empty()) {
		c = q.top();
		q.pop();

		if(c.board[2][9] == 'x') break;
		if(c.pm > max_pm) {
			cout << c.pm << " " << mem.size() << endl;
			mem.clear();
			max_pm = c.pm;
		}

		// Check if knights can move to vacant spot.
		for(pair<int, int> p : { make_pair(1, 2), make_pair(2, 1) }) {
			for(int diri : { -1, 1 }) {
				for(int dirj : { -1, 1 }) {
					check(c, 'k', diri * p.first, dirj * p.second);
				}
			}
		}

		// Check if bishops can move to vacant spot.
		for(int di : { -1, 1 }) {
			for(int dj : { -1, 1 }) {
				check(c, 'b', di, dj);
			}
		}

		// Check if rooks can move to vacant spot.
		for(char dir : { false, true }) {
			for(int d : { -1, 1 }) {
				check(c, 'r', dir * d, !dir * d);
			}
		}

		// check if king can move to vacant spot.
		for(int di = -1; di <= 1; di++) {
			for(int dj = -1; dj <= 1; dj++) {
				check(c, 'x', di, dj);
			}
		}

		// Check if pawns can move to vacant spot.
		check(c, 'p', 1, 0);
	}

	cout << c.m << " " << q.size() << " " << mem.size() << " " << cache << endl;

	for(int i = 2; i < 10; i++) {
		for(int j = 2; j < 10; j++) {
			cout << c.board[i][j];
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}