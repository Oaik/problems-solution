#include <iostream>
using namespace std;
char input[100];
int main() {
	input[0] = '1';
	int n = 0, t = 0, i = 1;
	cin >> n >> t;
	if (n == 1 && t == 10) {
	    cout << "-1";
	    return 0;
	}
	for (; (i <= t); ++i) {
		if ((i % t == 0))
			break;
	}
	for (int j = 1; j < n; ++j)
		input[j] = '0';
	if (i == 10) i -= 9;
	input[0] = i + '0';
	cout << input;
    return 0;
}