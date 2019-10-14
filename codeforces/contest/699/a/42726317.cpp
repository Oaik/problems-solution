#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, sec = 1000000000, len, l = 0, r = -1;
	string inp;
	cin >> n >> inp;
	len = inp.length();
	for (int i = 0; i < len; ++i) {
		if (inp[i] == 'R') {
			cin >> r;
		} else {
			cin >> l;
		}
		int diff = (l-r <= 0 || l-r == l+1) ? 2000000000 : l-r;
		sec = min(sec, (diff) / 2);
	}
	if (sec <= 0 || sec == 1000000000)
		cout << -1;
	else
		cout << sec;

}
