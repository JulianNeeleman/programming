#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

const set<char> vowels = { 'A', 'E', 'I', 'O', 'U', 'Y' };

int main() {
	string s;
	cin >> s;

	int jump = 1, ans = 1;
	for(const char &c : s) {
		if(vowels.find(c) != vowels.end()) ans = max(ans, jump), jump = 1;
		else jump++;
	}
	ans = max(ans, jump);
	cout << ans << endl;

	return 0;
}