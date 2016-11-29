#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
	int T;
	cin >> T;

	while(T--) {
		string a, b;
		cin >> a >> b;

		cout << a << endl << b << endl;
		for(int i = 0; i < a.size(); i++) {
			cout << (a[i] == b[i] ? '.' : '*');
		}
		cout << endl << endl;
	}


	return 0;
}