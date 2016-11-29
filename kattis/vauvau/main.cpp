#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int A, B, C, D;

string solve(int X) {
	int c = ((X % (A + B)) < A) + ((X % (C + D)) < C);
	if(c == 0) return "none";
	if(c == 1) return "one";
	return "both";
}

int main() {
	int P, M, G;
	cin >> A >> B >> C >> D >> P >> M >> G;

	cout << solve(P - 1) << endl;
	cout << solve(M - 1) << endl;
	cout << solve(G - 1) << endl;

	return 0;
}