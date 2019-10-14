#include <iostream>

using namespace std;

int main() {
	int n = 0, a = 0, d = 0;
	cin >> n;
	char s[n];
	cin >> s;

	for (int i = 0; i < n; ++i) {
		if (s[i] == 'A')
			++a;
		if (s[i] == 'D')
			++d;
	}

	if (a == d) {
		cout << "Friendship" << endl;
	} else {
		if (a > d) {
			cout << "Anton" << endl;
		} else {
			cout << "Danik" << endl;
		}
	}

	return 0;
}
