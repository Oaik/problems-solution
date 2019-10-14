#include <iostream>
using namespace std;

int main() {
	int a = 0, b = 0, c = 0, length = 0, result = 0;
	cin >> length;
	for (int i = 0; i < length; ++i) {
		cin >> a >> b >> c;
		if ((a == 1 && b == 1) || (a == 1 && c == 1) || (b == 1 && c == 1)) { // @suppress("Suggested parenthesis around expression")
			++result;
		}
	}
	cout << result;
	return 0;
}