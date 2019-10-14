#include <iostream>
using namespace std;

int main() {
	int cho = 0, n = 0, police = 0, count = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> cho;
		if (cho == -1 && police == 0) {
			++count;
		} else if (cho == -1) {
			--police;
		} else {
			police += cho;
		}
	}
	cout << count;
}
