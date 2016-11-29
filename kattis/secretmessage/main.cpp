#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int get_root(int n) {
	int root = 0;
	while(root * root < n) root++;
	return root;																																
}

int main() {
	int N;
	cin >> N;

	while(N--) {
		string s;
		cin >> s;																												
																																																																																																																																																															
		int root = get_root(s.size()),
			iv = max((int)s.size() - root, 0);
		for(int i = 0; i < iv; i++) s.push_back('*');
		
		int k = 0;
		vector<vector<char> > m(root, vector<char>(root));
		for(int i = 0; i < root; i++) for(int j = 0; j < root; j++) {
			m[i][j] = s[k++];
		}

		for(int j = 0; j < root; j++) for(int i = root - 1; i >= 0; i--) {
			if(m[i][j] != '*') cout << m[i][j];
		} 
		cout << endl;
	}

	return 0;
}