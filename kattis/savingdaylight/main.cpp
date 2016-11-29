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
	while(getline(cin, line)) {
		stringstream ss(line);

		string M;
		int D, Y;
		ss >> M >> D >> Y;
		cout << M << " " << D << " " << Y;

		int fh, fm, th, tm;
		char ig;
		ss >> fh >> ig >> fm >> th >> ig >> tm;

		int ft = 60 * fh + fm,
			tt = 60 * th + tm,
			dt = tt - ft;

		cout << " " << dt / 60 << " hours " << dt % 60 << " minutes" << endl;

	}

	return 0;
}