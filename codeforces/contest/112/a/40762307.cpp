#include<bits/stdc++.h>
#include <iostream>

using namespace std;

int main () {
	string firstInput; string secondInput;
	cin >> firstInput >> secondInput;
	int length = firstInput.length() > secondInput.length() ? firstInput.length() : secondInput.length();
	int result = 1;


	// using transform() function and ::toupper in STL
	transform(firstInput.begin(), firstInput.end(), firstInput.begin(), ::toupper);
	transform(secondInput.begin(), secondInput.end(), secondInput.begin(), ::toupper);


	for (int i = 0; i < length; ++i) {
		if ( (int)firstInput[i] == (int)secondInput[i] ) {
			result = 0;
			continue;
		} else if ( (int)firstInput[i] < (int)secondInput[i] ) {
			result = -1;
			break;
		} else {
			result = 1;
			break;
		}
	}

	cout << result;
	return 0;
}
