#include<bits/stdc++.h>
#include <iostream>

using namespace std;

int main () {
	string name;
	int countLower = 0, countUpper = 0;
	cin >> name;
	for (int i = 0; i < (int)name.length(); ++i) {
		if ( (int)name[i] < 91 ) {
			++countUpper;
		} else {
			++countLower;
		}
	}
	if (countLower == countUpper || countLower > countUpper)
		transform(name.begin(), name.end(), name.begin(), ::tolower);
	else
		transform(name.begin(), name.end(), name.begin(), ::toupper);

	cout << name;
	return 0;
}
