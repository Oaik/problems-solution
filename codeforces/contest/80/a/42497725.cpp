#include <iostream>
using namespace std;

int main() {
	int n, m, num = 0, i = 0;
	cin >> n >> m;
	while (n < m) {
		++n,i = 0, num = 0;;
		for (i = 2; i < 10; ++i) {
			if (n % i == 0 && n != i) {
				++num;
				break;
			}
		}
		if (num == 0) break;
	}
	if (n == m && num == 0)
		cout << "YES";
	else
		cout << "NO";
}