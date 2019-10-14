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

int const N = 200000 + 9, M = 100 + 9, OO = 1e9;

bool arr[N];

int main() {
	cout << fixed << setprecision(12);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	int cnt = 0, mxAns = 0;
	for (int i = 0; i < n; ++i) {
		if(arr[i])
			++cnt;
		else
			cnt = 0;
		mxAns = max(mxAns, cnt);
	}
	mxAns = max(mxAns, cnt);
	cnt = 0;
	int i;
	for (i = n-1; i >= 0; --i) {
		if(arr[i])
			++cnt;
		else
			break;
	}
	if(arr[n-1]) {
		for (int i = 0; i < n-1; ++i) {
			if(!arr[i])
				break;
			++cnt;
		}
	}
	cout << max(mxAns, cnt);
}