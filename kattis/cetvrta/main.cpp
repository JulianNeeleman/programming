#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	if(a == c) cout << e;
	else if(a == e) cout << c;
	else cout << a;

	cout << " ";

	if(b == d) cout << f;
	else if(b == f) cout << d;
	else cout << b;

	cout << endl;

	return 0;
}