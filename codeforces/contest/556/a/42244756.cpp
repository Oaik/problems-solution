#include <iostream>
using namespace std;

int main() {
	int n = 0, ones = 0, zeros = 0;
	string inp;
	cin >> n >> inp;
	for (int i = 0; i < (int)inp.length(); ++i) {
		if (inp[i] == '1')
			++ones;
		else
			++zeros;
	}
	cout << abs(ones-zeros);
}
