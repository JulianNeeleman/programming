#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
	double R, C;
	cin >> R >> C;
	cout << setprecision(20) << (100 * (R - C) * (R - C)) / (R * R) << endl; 
	return 0;
}