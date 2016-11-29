#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

pair<int, int> press(char ch) {
	if(ch == ' ') return { 0, 1 };

	int i = ch - 'a';
	if(i < 3) return { 2, i + 1 };
	else if(i < 6) return { 3, i - 2 };
	else if(i < 9) return { 4, i - 5 };
	else if(i < 12) return { 5, i - 8 };
	else if(i < 15) return { 6, i - 11 };
	else if(i < 19) return { 7 , i - 14 };
	else if(i < 22) return { 8, i - 18 };
	else return { 9, i - 21 };
}

int main() {
	int N;
	cin >> N;
	cin.ignore(256, '\n');

	for(int n = 1; n <= N; n++) {
		string ans = "", line;
		getline(cin, line);

		char last = '#';
		for(const char& ch : line) {
			pair<int, int> p = press(ch);
			char pc = p.first + '0';
			if(pc == last) ans += ' ';
			while(p.second--) ans += pc;
			last = pc;
		}

		cout << "Case #" << n << ": " << ans << endl;
	}

	return 0;
}