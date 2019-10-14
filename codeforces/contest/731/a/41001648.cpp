//#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	string input;
	cin >> input;
	int current = 97, strLen = input.length(), steps = 0;
	for (int i = 0; i < strLen; ++i) {
		int val = abs((input[i]-current)),
			val2 = abs(((input[i] - 26) - current)),
			val3 = min(val, val2),
			val4 = min(val3, abs(((input[i] + 26) - current)));
		steps += val4;

		current = (int)input[i];
	}
	cout << steps;
}
