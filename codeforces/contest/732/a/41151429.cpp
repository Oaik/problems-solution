#include <iostream>
using namespace std;

int main() {
	int a = 0, b = 0;
	cin >> a >> b;
	for (int i = 1; i <= 9; ++i) {
		int mul = a * i;
		string intStr = to_string(mul);
		char last = intStr[intStr.length() - 1];
		// "1" in ascii -> 49 and "0" -> 48 So to get it int we need to 49 - 48 which = 1 instead we can make a trick -'0'
		if ( ((last - '0') == b) || ((mul % 10) == 0)) {
			cout << i;
			break;
		}
	}
}
