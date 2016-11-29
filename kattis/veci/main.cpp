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
	if(next_permutation(s.begin(), s.end())) {
		cout << s << endl;
	} else {
		cout << 0 << endl;
	}
	return 0;
}