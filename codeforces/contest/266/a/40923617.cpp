//============================================================================
// Name        : hello.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int n = 0, count = 0;
	cin >> n;
	string stones;
	cin >> stones;
	for (int i = 0; i <= n - 1; ++i) {
		if (stones[i] == stones[i-1])
			++count;
	}
	cout << count;
}
