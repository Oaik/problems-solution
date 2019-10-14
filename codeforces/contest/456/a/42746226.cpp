#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

long long price[100000], quality[100000];
int main() {
	long long n;
	cin >> n;
	for (long long i = 0; i < n; ++i)
		cin >> price[i] >> quality[i];
	if (n < 10) {
		for (long long i = 0; i < n; ++i) {
			for (long long j = 0; j < n; ++j) {
				if (price[i] < price[j] && quality[i] > quality[j]) {
					cout << "Happy Alex";
					return 0;
				}
			}

		}
	} else {
		for (long long i = 0; i < n-1; ++i) {
			if (price[i] < price[i+1] && quality[i] > quality[i+1]) {
				cout << "Happy Alex";
				return 0;
			}
		}
	}
	cout << "Poor Alex";

}
