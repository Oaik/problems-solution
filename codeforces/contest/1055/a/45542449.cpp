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

bool arr1[1001], arr2[1001];

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n, s;
	bool found = false;
	cin >> n >> s;
	for (int i = 0; i < n; ++i)
		cin >> arr1[i];
	for (int i = 0; i < n; ++i)
		cin >> arr2[i];
	--s;
	if (arr1[0] == 0 || (arr1[s] == 0 && arr2[s] == 0)) {
		cout << "NO";
		return 0;
	}
	if (arr1[s] == 1) {
		cout << "YES";
		return 0;
	}
	for (int i = s; i < n && !found; ++i) {
		if(arr1[i] == 1 && arr2[i] == 1)
			found = true;
	}
	if (found) cout << "YES";
	else cout << "NO";
	return 0;
}
