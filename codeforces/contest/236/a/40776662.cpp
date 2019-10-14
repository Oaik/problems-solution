#include <iostream>
#include <string>

using namespace std;

int main () {
	string firstInput;
	cin >> firstInput;
	int result = firstInput.length();
	// sort the string
	for (int j = 0; j < result; ++j) {
		int copy = firstInput[j];
		int k = j - 1;
		while(k >=0 && copy < firstInput[k]) {
			firstInput[k+1] = firstInput[k];
			--k;
		}
		firstInput[k+1] = copy;
	}
	// subtruct 1 from the result if found 2 smillar letters
	for (int i = 0; i < (int)firstInput.length(); ++i) {
		if (firstInput[i] == firstInput[i + 1])
			--result;
	}
	if (result % 2 == 0) {
		cout << "CHAT WITH HER!";
	} else {
		cout << "IGNORE HIM!";
	}
	return 0;
}
