#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <sstream>

using namespace std;

int main() {
	string line;
	int t = 1;
	while(getline(cin, line)) {
		stringstream ss(line);
		string note, tonality;
		ss >> note >> tonality;

		cout << "Case " << t++ << ": ";

		if(note.size() == 1) {
			cout << "UNIQUE" << endl;
			continue;
		} else if(note[1] == 'b') {
			if(note[0] == 'A') note[0] = 'G';
			else note[0]--;
			note[1] = '#';
		} else {
			if(note[0] == 'G') note[0] = 'A';
			else note[0]++;
			note[1] = 'b';
		}

		cout << note << " " << tonality << endl;
	}

	return 0;
}