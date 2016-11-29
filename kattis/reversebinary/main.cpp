#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <bitset>

using namespace std;

int main() {
	int64_t a;
	cin >> a;

	bitset<64> bs(a);
	string r = "";

	for(int i = 0; i < 64; i++) {
		r += bs[i] ? '1' : '0';
	}

	while(*r.rbegin() == '0') r.pop_back();
	reverse(r.begin(), r.end());
	
	int64_t ans = 0;
	for(int i = 0; i < r.size(); i++) {
		ans += (r[i] == '1') * pow(2, i);
	}	

	cout << ans << endl;

	return 0;
}