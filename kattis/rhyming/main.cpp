#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <sstream>

using namespace std;

bool check(string a, string b) {
	int i = a.size() - 1, j;
	for(j = b.size() - 1; j >= 0 && i >= 0; i--, j--) {
		if(a[i] != b[j]) return false;
	}
	return j == -1;
}

int main() {
	string S;
	cin >> S;
	int E;
	cin >> E;
	cin.ignore(256, '\n');

	vector<string> dict;
	for(int i = 0; i < E; i++) {
		string buffer, exit;
		bool rhyme = false;
		getline(cin, buffer);
		stringstream ss(buffer);
		vector<string> list;
		
		while(ss >> exit) {
			rhyme |= check(S, exit);
			list.push_back(exit);
		}

		if(rhyme) for(const string &w : list) {
			dict.push_back(w);
		}
	}

	int P;
	cin >> P;
	cin.ignore(256, '\n');

	for(int i = 0; i < P; i++) {
		string buffer, exit;
		getline(cin, buffer);
		stringstream ss(buffer);

		while(ss >> exit);

		bool found = false;
		for(const string &w : dict) {
			if(check(exit, w)) {
				cout << "YES" << endl;
				found = true;
				break;
			}
		}
		if(!found) cout << "NO" << endl;
	}

	return 0;
}