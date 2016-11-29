#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {

	while(true) {
		int w, l;
		cin >> w >> l;
		if(w == 0 && l == 0) break;

		int n;
		cin >> n;
		int x = 0, y = 0, ax = 0, ay = 0;
		for(int i = 0; i < n; i++) {
			char d;
			int s;
			cin >> d >> s;
			
			switch(d) {
				case 'u': y += s, ay = min(l - 1, ay + s); break;
				case 'd': y -= s, ay = max(0, ay - s); break;
				case 'r': x += s, ax = min(w - 1, ax + s); break;
				case 'l': x -= s, ax = max(0, ax - s); break;
			}
		}

		cout << "Robot thinks " << x << " " << y << endl;
		cout << "Actually at " << ax << " " << ay << endl;
		cout << endl;
	}

	return 0;
}