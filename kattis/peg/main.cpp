#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
	vector<vector<char> > b(9, vector<char>(9, 'x'));
	for(int i = 1; i <= 7; i++) {
		string buffer;
		getline(cin, buffer);
		for(int j = 1; j <= 7; j++) {
			b[i][j] = buffer[j - 1];
		}
 	}

 	int ans = 0;

 	for(int i = 1; i <= 7; i++) {
 		for(int j = 1; j <= 7; j++) {
 			for(bool d : { true, false }) {
 				for(int v : { -1, 1 }) {
 					if(b[i][j] == 'o' && 
 						b[i + d * v][j + !d * v] == 'o' &&
 						b[i + 2 * d * v][j + 2 * !d * v] == '.') ans++;
 				}
 			}
 		}
 	}

 	cout << ans << endl;

	return 0;
}