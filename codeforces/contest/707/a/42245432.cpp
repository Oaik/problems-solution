#include <iostream>
using namespace std;

int main() {
	int n = 0, m = 0;
	char inp;
	cin >> n >> m;
	for (int i = 0; i < n*m; ++i) {
		cin >> inp;
		if (inp == 'C' || inp == 'M' || inp == 'Y') {
			cout << "#Color";
			return 0;
		}
	}
	cout << "#Black&White";
}
