#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	cin.ignore(256, '\n');

	while(N--) {
		string line;
		getline(cin, line);
		if(line.size() >= 10 && line.substr(0, 10) == "Simon says") {
			cout << line.substr(11, -1) << endl;
		}
	}

	return 0;
}