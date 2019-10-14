#include <bits/stdc++.h>
using namespace std;


int main() {
	int n = 0, counter = 0;
	long long x = 0;
	cin >> n;
	if (n <= 2) {
		cout << 0;
		return 0;
	}
	vector<long long> v2;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		v2.push_back(x);
	}
	sort(v2.begin(), v2.end());
	counter += count(v2.begin(), v2.end(), v2[0]) - 1;
	counter += count(v2.begin(), v2.end(), *(v2.end()-1)) - 1;
	if(n - counter - 2 <= 0)
		cout << 0;
	else
		cout << n - counter - 2;
}
