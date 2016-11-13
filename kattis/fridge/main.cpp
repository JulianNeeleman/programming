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

	vector<int> dig(10);
	for(const char& ch : s) {
		dig[ch - '0']++;
	}

	int j = 1;
	for(int i = 2; i < 10; i++) {
		if(dig[i] < dig[j]) j = i;
	}

	if(dig[0] + 1 <= dig[j]) {
		int k = 1;
		while(dig[k] == 0 && k < 10) k++;
		if(k == 10) {
			cout << 1 << endl;
			return 0;
		} else {
			cout << k;
			for(int l = 0; l <= dig[0]; l++) cout << 0;
			cout << endl;
		}
	} else {
		for(int k = 0; k <= dig[j]; k++) {
			cout << j;
		} 
		cout << endl;
	}

	return 0;
}