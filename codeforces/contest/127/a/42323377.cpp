#include <bits/stdc++.h>
using namespace std;


int main() {
	int n, multi, fromX, fromY, toX, toY;
	float total = 0;
	cin >> n >> multi;
	cin >> fromX >> fromY;
	for (int i = 1; i < n; ++i) {
		cin >> toX >> toY;
		total += sqrt(pow(fromX-toX, 2) + pow(fromY-toY, 2));
		fromX = toX, fromY = toY;
	}
	cout << setprecision(9) << ( total / 50 ) * multi;
}
