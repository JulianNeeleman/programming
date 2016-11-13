#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <climits>

using namespace std;

map<vector<vector<bool> >, int> mem;

int rec(vector<vector<bool> > b) {
	if(mem.find(b) != mem.end()) return mem[b];
	mem.insert({b, 512});
	int res = INT_MAX;
	for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) {
		vector<vector<bool> > new_b(b.begin(), b.end());
		new_b[i][j] = !new_b[i][j];
		if(i > 0) new_b[i - 1][j] = !new_b[i - 1][j];
		if(j > 0) new_b[i][j - 1] = !new_b[i][j - 1];
		if(i < 2) new_b[i + 1][j] = !new_b[i + 1][j];
		if(j < 2) new_b[i][j + 1] = !new_b[i][j + 1];
		res = min(res, rec(new_b) + 1);
	}
	mem[b] = res;
	return res;
}

int main() {
	int P;
	cin >> P;

	mem.insert({ vector<vector<bool> >(3, vector<bool>(3)), 0 });
	
	while(P--) {
		vector<vector<bool> > b(3, vector<bool>(3));
		for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) {
			char c;
			cin >> c;
			b[i][j] =  c == '*'; 
		}

		cout << rec(b) << endl;
		mem.clear();
		mem.insert({ vector<vector<bool> >(3, vector<bool>(3)), 0 });
	}

	return 0;
}