#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;


map<char, string> ttm;
map<string, char> mtt;


void add(char a, string b) {
	ttm[a] = b;
	mtt[b] = a;
}

void build() {
	add('A', ".-");
	add('B', "-...");
	add('C', "-.-.");
	add('D', "-..");
	add('E', ".");
	add('F', "..-.");
	add('G', "--.");
	add('H', "....");
	add('I', "..");
	add('J', ".---");
	add('K', "-.-");
	add('L', ".-..");
	add('M', "--");
	add('N', "-.");
	add('O', "---");
	add('P', ".--.");
	add('Q', "--.-");
	add('R', ".-.");
	add('S', "...");
	add('T', "-");
	add('U', "..-");
	add('V', "...-");
	add('W', ".--");
	add('X', "-..-");
	add('Y', "-.--");
	add('Z', "--..");

	add('_', "..--");
	add(',', ".-.-");
	add('.', "---.");
	add('?', "----");
}

pair<string, vector<int> > to_morse(string s) {
	string morse = "";
	vector<int> ls;
	for(const char& ch : s) {
		morse += ttm[ch];
		ls.push_back(ttm[ch].size());
	}
	return { morse, ls };
}

int main() {
	build();

	string line;
	while(getline(cin, line)) {
		pair<string, vector<int> > p = to_morse(line);
		reverse(p.second.begin(), p.second.end());
		int from = 0;
		for(const int& l : p.second) {
			string code = p.first.substr(from, l);
			cout << mtt[code];
			from += l;
		}
		cout << endl;
	}

	return 0;
}