#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
	
	while(true) {
		int n;
		cin >> n;
		if(n == -1) break;

		vector<vector<int> > adj(n, vector<int>(n));
		for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
			cin >> adj[i][j];
		}

		vector<bool> strong(n);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				for(int k = 0; k < n; k++)
					if(adj[i][j] && adj[j][k] && adj[i][k]) strong[i] = true;
	
		for(int i = 0; i < n; i++) {
			if(!strong[i]) cout << i << " ";
		}
		cout << endl;
	}

	return 0;
}