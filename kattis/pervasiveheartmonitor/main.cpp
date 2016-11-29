#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
	string line;
	while(getline(cin, line)) {
		stringstream ss(line);
		vector<string> name;
		string w;
		double n = 0,
			c = 0.0;
		
		while(ss >> w) {
			if(w[0] >= '0' && w[0] <= '9') {
				stringstream ds(w);
				double v;
				ds >> v;
				c += v, n++;
			} else {
				name.push_back(w);
			}
		}

		cout << setprecision(20) << c / n;
		for(const string& nm : name) cout << " " << nm;
		cout << endl;
	}

	return 0;
}