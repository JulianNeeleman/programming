#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

map<char, string> m;

void build() {
	m['a'] = "@";
	m['b'] = "8";
	m['c'] = "(";
	m['d'] = "|)";
	m['e'] = "3";
	m['f'] = "#";
	m['g'] = "6";
	m['h'] = "[-]";
	m['i'] = "|";
	m['j'] = "_|";
	m['k'] = "|<";
	m['l'] = "1";
	m['m'] = "[]\\/[]";
	m['n'] = "[]\\[]";
	m['o'] = "0";
	m['p'] = "|D";
	m['q'] = "(,)";
	m['r'] = "|Z";
	m['s'] = "$";
	m['t'] = "']['";
	m['u'] = "|_|";
	m['v'] = "\\/";
	m['w'] = "\\/\\/";
	m['x'] = "}{";
	m['y'] = "`/";
	m['z'] = "2";
}

int main() {
	build();

	string line;
	getline(cin, line);

	for(const char& ch : line) {
		if(ch >= 'a' && ch <= 'z') cout << m[ch];
		else if(ch >= 'A' && ch <= 'Z') cout << m[tolower(ch)];
		else cout << ch;
	}
	cout << endl;

	return 0;
}