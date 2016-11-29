#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	cout << max(B - A - 1, C - B - 1) << endl;
	return 0;
}