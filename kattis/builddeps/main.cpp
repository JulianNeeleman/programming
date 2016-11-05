#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <iomanip>
#include <algorithm>
#include <map>
#include <random>
#include <cstdint>
#include <sstream>

using namespace std;

vector<int> topological_sort(vector<vector<int> > &g) {
	int n = g.size();

	vector<int> in_degs(n);
	for(int u = 0; u < n; u++) for(const int &v : g[u]) {
		in_degs[v]++;
	}

	queue<int> s;
	for(int u = 0; u < n; u++) if(in_degs[u] == 0) s.push(u);

	vector<int> order;
	while(!s.empty()) {
		int u = s.front();
		s.pop();
		order.push_back(u);

		for(const int &v : g[u]) {
			in_degs[v]--;
			if(in_degs[v] == 0) s.push(v);
		}
	}

	return order;
}

vector<string> topological_sort(map<string, vector<string> > &g, map<string, int> &in_degs) {
	for(const pair<string, vector<string> > &p : g) {
		for(const string &v : p.second) in_degs[v]++;
	}

	queue<string> q;
	for(const pair<string, int> &p : in_degs) {
		if(p.second == 0) q.push(p.first);
	}

	vector<string> order;
	while(!q.empty()) {
		string u = q.front();
		q.pop();
		order.push_back(u);

		for(const string &v : g[u]) {
			in_degs[v]--;
			if(in_degs[v] == 0) q.push(v);
		}
	}

	return order;
}

vector<string> split(string buffer) {
	vector<string> result;
	stringstream ss;
	ss.str(buffer);
	string item;
	while(ss >> item) result.push_back(item);
	return result;
}

void bfs(map<string, vector<string> > &g, string c, set<string> &comp) {
	queue<string> q;
	q.push(c);
	comp.insert(c);

	while(!q.empty()) {
		string u = q.front();
		q.pop();
		for(const string &v : g[u]) {
			if(comp.find(v) == comp.end()) {
				q.push(v);
				comp.insert(v);
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	cin.ignore(256, '\n');

	map<string, vector<string> > g;
	map<string, int> in_degs;

	for(int i = 0; i < n; i++) {
		string buffer;
		getline(cin, buffer);
		vector<string> line = split(buffer);
		line[0].pop_back();
		in_degs[line[0]] = 0;
		for(int i = 1; i < line.size(); i++) {
			g[line[i]].push_back(line[0]);
		}
	}

	vector<string> ts = topological_sort(g, in_degs);

	string c;
	cin >> c;
	
	set<string> comp;
	bfs(g, c, comp);

	for(const string &u : ts) if(comp.find(u) != comp.end()) {
		cout << u << endl;
	}

	return 0;
}