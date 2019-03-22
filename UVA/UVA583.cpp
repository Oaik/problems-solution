#include <bits/stdc++.h>
using namespace std;

vector<long long> primeVect(long long n) {
	vector<long long> vec;
	long long i;
	for (i = 2; i * i <= n; ++i) {
		while(n % i == 0) {
			vec.push_back(i);
			n /= i;
		}
	}
	if(n > 1)
		vec.push_back(n);
	return vec;
}

int main() {
	long long n;
	while(cin >> n, n) {
		if(n < 0) {
			cout << n << " = " << "-1 x ";
			n *= -1;
		} else {
			cout << n << " = ";
		}
		if(n == 1) {
			cout << '\n';
			continue;
		}
		vector<long long> vec = primeVect(n);
		sort(vec.begin(), vec.end());
		long long z = vec.size();
		cout << vec[0];
		for (long long i = 1; i < z; ++i) {
			cout << " x " << vec[i];
		}
		cout << '\n';
	}

}

