#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	cin.ignore(256, '\n');

	while(N--) {
		string line;
		getline(cin, line);
		
		set<char> s;
		for(const char& ch : line) {
			if(ch >= 'A' && ch <= 'Z') s.insert(tolower(ch));
			else if(ch >= 'a' && ch <= 'z') s.insert(ch);
		}

		if(s.size() == 26) cout << "pangram" << endl;
		else {
			cout << "missing ";
			for(char ch = 'a'; ch <= 'z'; ch++) {
				if(s.find(ch) == s.end()) cout << ch;
			}
			cout << endl;
		}
	}


	return 0;
}