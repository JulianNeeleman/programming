#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
	string s;
	cin >> s;
	int n = s.size();

	set<string> m;
	int P = 13, K = 13, H = 13, T = 13;

	for(int i = 0; i < n; i += 3) {
		char c = s[i];
		string v = to_string(c);
		v.push_back(s[i + 1]);
		v.push_back(s[i + 2]);

		if(m.find(v) != m.end()) {
			cout << "GRESKA" << endl;
			return 0;
		} else {
			m.insert(v);
			switch(c) {
				case 'P': P--; break;
				case 'K': K--; break;
				case 'H': H--; break;
				case 'T': T--; break;
			}
		}
	}

	cout << P << " " << K << " " << H << " " << T << endl;

	return 0;
}