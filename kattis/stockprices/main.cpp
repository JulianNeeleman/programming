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
		int n;
		cin >> n;

		int s = -1;
		multiset<int> buy, sell;
		for(int i = 0; i < n; i++) {
			string bs, ig;
			int m, v;
			cin >> bs >> m >> ig >> ig >> v;
			//cout << m << " " << v << endl;
			if(bs == "buy") for(int j = 0; j < m; j++) buy.insert(v);
			else for(int j = 0; j < m; j++) sell.insert(v);
			while(!buy.empty() && !sell.empty() && *buy.rbegin() >= *sell.begin()) {
				s = *sell.begin();
				buy.erase(prev(buy.end()));
				sell.erase(sell.begin());
			}

			if(sell.empty()) cout << "- ";
			else cout << *sell.begin() << " ";

			if(buy.empty()) cout << "- ";
			else cout << *buy.rbegin() << " ";

			if(s == -1) cout << "-" << endl;
			else cout << s << endl;
		}
	}

	return 0;
}