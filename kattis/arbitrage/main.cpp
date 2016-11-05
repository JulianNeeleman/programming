#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int T = 0;

struct Fraction {
	int64_t n, d;

	bool operator<(const Fraction &rhs) const {
		if(T == 63) cout << n * rhs.d << " > " << rhs.n * d << endl;
		return n * rhs.d < rhs.n * d; 
	}

	friend Fraction operator+(const Fraction &lhs, const Fraction &rhs);	
};

int64_t gcd(int64_t a, int64_t b) {
    return b == 0 ? a : gcd(b, a % b);
}

Fraction operator*(const Fraction &lhs, const Fraction &rhs) {
	int64_t n = lhs.n * rhs.n,
		d = lhs.d * rhs.d,
		gcf = gcd(n, d);
	return {n / gcf, d / gcf};
}

int64_t C, R, A, B;
string F, S, ign;
char colon;
set<string> seen;
map<string, Fraction> mem;
map<string, vector<pair<string, Fraction> > > g;


bool dfs(string c, Fraction f) {
	if(T == 63) cout << f.n << " " << f.d << endl;
	if(mem.find(c) != mem.end()) {
		if(T == 63) cout << "back edge " << mem[c].n << "/" << mem[c].d << endl;
		return mem[c] < f;
	}
	if(seen.find(c) != seen.end()) return false;

	mem[c] = f;
	seen.insert(c);
	bool res = false;

	for(const pair<string, Fraction> p : g[c]) {
		res |= dfs(p.first, f * p.second);
	}

	mem.erase(c);

	return res;
}

int main() {
	while(true) {
		T++;
		seen.clear();
		g.clear();
		cin >> C;
		if(C == 0) break;
		for(int i = 0; i < C; i++) {
			cin >> ign;
		}

		cin >> R;
		for(int i = 0; i < R; i++) {
			cin >> F >> S >> A >> colon >> B;
			if(T == 63) cout << F << " " << S << " " << A << ":" << B << endl;
			g[F].push_back({S, {B, A}});
		}

		bool ans = false;
		for(const pair<string, vector<pair<string, Fraction> > > p : g) {
			if(seen.find(p.first) != seen.end()) continue;
			mem.clear();
			ans |= dfs(p.first, {1, 1});
		}

		cout << (ans ? "Arbitrage" : "Ok") << endl;
	}

	return 0;
}