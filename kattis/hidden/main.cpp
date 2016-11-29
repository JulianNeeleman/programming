#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
	string P, S;
	cin >> P >> S;

	multiset<char> ps(P.begin(), P.end());
	int i = 0;
	for(const char& ch : S) {
		if(i == P.size()) break;
		if(ps.find(ch) != ps.end()) {
			ps.erase(ps.find(ch));
			if(ch != P[i]) {
				cout << "FAIL" << endl;
				return 0;
			}
			i++;
		}
	}

	cout << (i == P.size() ? "PASS" : "FAIL") << endl;

	return 0;
}