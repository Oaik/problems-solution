#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define all(v)  	((v).begin()),((v).end())
#define sz(x)  		((ll) (x).size())
#define clr(a,b)	memset(a,b,sizeof(a))
const double EPS = 1e-8;
const double pi = acos(-1);
ll dcmp(double a, double b) {
	return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1;
}
void debug() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "rt", stdin);
//	freopen("output.in", "wt", stdout);
#endif
}

int const N = 1e5 + 9, M = 100 + 9, OO = 1e9;

int arr[N];

unsigned long long C(unsigned long long na, unsigned long long k) {
	if (k > na) {
		return 0;
	}
	if(na <= 0) {
		return 0;
	}
	unsigned long long r = 1;
	for (unsigned long long d = 1; d <= k; ++d) {
		r *= na--;
		r /= d;
	}
	return r;
}

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	bool en = 0;
	int pt1 = 0, pt2 = 2, inc = 1, dif = 0, prv = 0;
	ll totalSum = 0;
	while (pt2 < n) {
		if (arr[pt2] - arr[pt1] <= k) {
			dif += inc;
			++inc;
			++pt2;
			en = 1;
		} else {
			if (pt2 - pt1 == 2) {
				++pt2, ++pt1;
			} else {
				++pt1;
			}
			if (en) {
				totalSum += (C(pt2 - pt1 + 1, 3));
				if(prv-pt1 >= 0)
					totalSum -= C(prv-pt1+1, 3);
				prv = pt2;
			}
			inc = 1, dif = 0, en = 0;
		}
	}
	totalSum += (C(pt2 - pt1, 3));
	if(prv-pt1 >= 0)
		totalSum -= C(prv-pt1, 3);
	cout << totalSum;
}
