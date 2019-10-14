#include <bits/stdc++.h>

using namespace std;

int main() {
	double n;
	cin >> n;
	if ((long long)n % 2 != 0) cout << "-";
	cout.setf(ios::fixed);
	cout << setprecision(0) << ceil(n/2);
}

