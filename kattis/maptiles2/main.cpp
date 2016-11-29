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

	reverse(s.begin(), s.end());
	int64_t x = 0, y = 0, dx = 1, dy = 1;
	for(const char& ch : s) {
		if(ch == '0');
		else if(ch == '1') x += dx;
		else if(ch == '2') y += dy;
		else x += dx, y += dy;
		dx *= 2, dy *= 2;
	}

	cout << n << " " << x << " " << y << endl;
	return 0;
}