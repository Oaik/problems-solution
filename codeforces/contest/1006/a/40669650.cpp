//============================================================================
// Name        : rtesst.cpp
// Author      : omar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

int main() {
	int n = 0;
	cin >> n;
	int arrNum[n];

	for (int z = 0; z < n; z++) {
	    cin >> arrNum[z];
	}

	for (int i = 0; i < n; ++i) {
		if ( arrNum[i] % 2 != 0) {
			arrNum[i] = arrNum[i] + 1;
		}
	}

	for (int i = 0; i < n; ++i) {
		arrNum[i] = arrNum[i] - 1;
	}

	for (int z = 0; z < n; z++) {
			if ( z == n-1) {
				cout << arrNum[z];
			} else {
				cout << arrNum[z] << " ";
			}
		}

	return 0;
}
