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

int const N = 3e5 + 9, M = 100 + 9, OO = 1e9;

int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int arr[2000];

int main() {
	cout << fixed << setprecision(12);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
//	debug();
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	for (int i = 1; i <= 12; ++i) {
		month[i] += month[i-1];
	}
	int n;
	cin >> n;
	int m, d, p, t, start = 0, end;
	while(n--) {
		cin >> m >> d >> p >> t;
		start = month[m-1] + d - t+200, end = month[m-1]+d+200;
		for (int i = start; i < end; ++i) {
			arr[i] += p;
		}
	}
	cout << *max_element(arr, arr+2000);
	return 0;
}
