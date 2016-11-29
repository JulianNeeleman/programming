#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
	vector<string> ws;
	string w;
	
	while(cin >> w) ws.push_back(w);

	set<string> cs;
	for(const string& a : ws) for(const string& b : ws) {
		if(a == b) continue;
		cs.insert(a + b);
	}

	for(const string& s : cs) cout << s << endl;

	return 0;
}