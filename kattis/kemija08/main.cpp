#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

set<char> vs = { 'a', 'e', 'i', 'o', 'u' };

int main() {
	string line;
	getline(cin, line);

	for(int i = 0; i < line.size(); i++) {
		cout << line[i];
		if(vs.find(line[i]) != vs.end()) i += 2;
	}
	cout << endl;

	return 0;
}