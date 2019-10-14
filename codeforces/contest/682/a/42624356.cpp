#include <bits/stdc++.h>
using namespace std;

int main() {
	long long x,y, total = 0;
	cin >> x >> y;
	long long sums[6];
	memset(sums, 0, sizeof(sums));
	for (int i = 1; i <= y; ++i)
		++sums[i%5];
	for (int j = 1; j <= x; ++j)
		total += sums[5-(j%5)];
	cout << total + (sums[0] * ((int)x/5));
}

