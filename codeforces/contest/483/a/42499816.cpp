#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long long x = 0, y = 0, diff = 0;
	int num = 0;
	cin >> x >> y;
	diff = y-x;
	if (diff < 2) {
		cout << -1;
		return 0;
	}
	for (long long k = 0; k < y-x-1; ++k) {
		for (int j = 2; j <= y-x; ++j) {
			for (long long i = 2; i < 10; ++i) {
				if ((x+k) % i == 0 && (x+k+j) % i == 0) {
					for (int a = 2; a < 10; ++a) {
						if ( (x+k+j) % a == 0 && (x+k+1) % a == 0 ) ++num;
					}
					if (!num) {
						cout << x+k << " " << x+k+1 << " " << x+k+j;
						return 0;
					}
					num = 0;
				}
			}
		}
	}


	cout << -1;
}

