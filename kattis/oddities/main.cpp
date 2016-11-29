#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;

		cout << a << " is " << ((a + 20) % 2 == 0 ? "even" : "odd") << endl; 
	}

	return 0;
}