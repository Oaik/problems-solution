#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int n, r = 0, l = 0, startR = 0, startL = 0;
	string inp;
	cin >> n >> inp;
	for (int i = (int)inp.length() - 1; i >= 0; --i) {
			if (inp[i] == 'L') {
				startR = i + 1;
				break;
			} else if (inp[i] == 'R') {
				startL = i+ 1;
				break;
			}
	}
	for (int i = 0; i < (int)inp.length(); ++i) {
		if (inp[i] == '.') continue;
		else if (inp[i] == 'R') ++r;
		else ++l;
	}
	if (startR)
		cout << startR << " " << startR - (l);
	else
		cout << startL << " " << startL + 1;
}
