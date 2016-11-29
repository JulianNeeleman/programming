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

	int T = 0, C = 0, G = 0;
	for(const char& ch : s) {
		switch(ch) {
			case 'T': T++; break;
			case 'C': C++; break;
			default: G++;
		}
	}

	cout << T * T + C * C + G * G + 7 * min(T, min(C, G)) << endl;

	return 0;
}