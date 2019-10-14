#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n,m,a,col = 0, row = 0;
	cin >> n >> m >> a;

	row = (n %  a == 0 ) ? (n / a) : (n/a) + 1, col = (m %  a == 0 ) ? (m / a) : (m/a) + 1;
	cout << col * row;
}

