#include <bits/stdc++.h>

using namespace std;
#define ll long long

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

vector<int> vec1;
vector<int> vec2;

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n, a, lastX, lastY;
	ll sumX = 0, sumY = 0;
	bool player = true; // T -> 1st
	cin >> n;
	vec1 = vector<int>(n + 1, 0);
	vec2 = vector<int>(n + 1, 0);
	for (int i = 0; i < n; ++i) {
		cin >> a;
		if (a > 0) {
			player = true;
			sumX += a;
			vec1.push_back(a);
		} else {
			player = false;
			sumY += abs(a);
			vec2.push_back(abs(a));
		}
	}
	if (sumX > sumY) {
		cout << "first";
	} else if (sumX == sumY) {
		int szvec = max(vec1.size(), vec2.size());
		for (int i = 0; i < szvec; ++i) {
			if (vec1[i] > vec2[i]) {
				cout << "first";
				return 0;
			} else if (vec1[i] < vec2[i]) {
				cout << "second";
				return 0;
			}
		}
		if (player)
			cout << "first";
		else
			cout << "second";
	} else {
		cout << "second";
	}
}
