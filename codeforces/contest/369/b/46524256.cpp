#include <bits/stdc++.h>

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define clr(arr, k) (memset(arr, k, sizeof(arr)))
#define lpv(i,a,n) 	for(int i=a;i<(int)n;i++)
#define ll long long

using namespace std;

const double EPS = (1e-8);
const double PI = acos(-1.0);
const ll INF = 1e9;

int dcmp(double x, double y) {
	return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}
void contest() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);
#endif
}

using namespace std;

int main() {
	int n, k, l, r, sall, sk;
	cin >> n >> k >> l >> r >> sall >> sk;
	int c = k;
	int rem = sall - sk, x = n-k;
	for (int i = 0; i < c; ++i) {
		if(sk/k > r) {
			cout << r << " ";
			sk -= r, k--;
		} else if (sk/k < l) {
			cout << l << " ";
			sk -= l, k--;
		} else {
			cout << (sk/k) << " ";
			sk -= (sk/k), k--;
		}
	}
	c = n-c;
	for (int i = 1; i <= c; ++i) {
		if (i == c) {
			cout << rem;
			break;
		}
		if(rem/x > r) {
			cout << r << " ";
			rem -= r, x--;
		} else if (rem/x < l) {
			cout << l << " ";
			rem -= l, x--;
		} else {
			cout << (rem/x) << " ";
			rem -= (rem/x), x--;
		}
	}
	return 0;
}
