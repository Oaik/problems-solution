#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <iomanip>
//#include <complex>

using namespace std;

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define clr(arr, k) (memset(arr, k, sizeof(arr)))
#define lpv(i,a,n) 	for(int i=a;i<(int)n;i++)
#define ll long long

//#define X real()
//#define Y imag()
//typedef complex<double> point;
//
//#define angle(a)  (atan2((a).Y, (a).X))
//#define dp(a, b)  ((conj(a) * (b)).real())
//#define cp(a, b)  ((conj(a) * (b)).imag())
//#define length(a) (dp(a, a))
//#define rotate0(p, ang) ((p) * exp(point(0, ang)))
//#define rotateA(p, ang, about) ((rotate0(p, ang)) + about)
//#define reflect0(v, m) (conj((v) / (m)) * (m))

const double EPS = (1e-7);
const double PI = acos(-1.0);
const ll INF = 1e9;

int dcmp(double x, double y) {
	return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

void contest() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n, h, a, b, k, t1, f1, t2, f2;
	ll cnt = 0;
	cin >> n >> h >> a >> b >> k;
	for (int i = 0; i < k; ++i) {
		cin >> t1 >> f1 >> t2 >> f2;
		cnt = 0;
		if (t1 == t2) {
			cout << abs(f1-f2) << "\n";
			continue;
		}
		if (f1 > b) {
			cnt = abs(f1-b);
			f1 = b;
		} else if (f1 < a) {
			cnt = abs(f1-a);
			f1 = a;
		}
		cnt += abs(t2-t1) + abs(f1-f2);
		cout << cnt << "\n";
	}
	return 0;
}
