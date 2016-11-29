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
		string name;
		int pss, bd, c;
		char ig;

		cin >> name >> pss >> ig >> c >>
			ig >> c >> bd >> ig >> c >> ig >>
			c >> c;

		cout << name << " ";
		if(pss >= 2010 || bd >= 1991) cout << "eligible";
		else if(c > 40) cout << "ineligible";
		else cout << "coach petitions";
		cout << endl;
	}
	return 0;
}