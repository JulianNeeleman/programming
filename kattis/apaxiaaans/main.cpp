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
	char l = '0';
	for(const char& ch : s) {
		if(ch != l) cout << ch;
		l = ch;
	}
	cout << endl;
	return 0;
}