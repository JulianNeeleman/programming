#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
	string s;
	cin >> s;

	vector<int> ans(4);
	for(const char& ch : s) {
		if(ch == '_') ans[0]++;
		else if(ch >= 'a' && ch <= 'z') ans[1]++;
		else if(ch >= 'A' && ch <= 'Z') ans[2]++;
		else ans[3]++;
	}

	for(const int& v : ans) {
		cout << setprecision(20) << (double)v / (double)s.size() << endl;
	}

	return 0;
}