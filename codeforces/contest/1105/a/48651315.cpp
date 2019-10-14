#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define all(v)  	((v).begin()),((v).end())
#define sz(x)  		((int) (x).size())
#define clr(a,b)	memset(a,b,sizeof(a))
const double EPS = 1e-8;
const double pi = acos(-1);

int dcmp(double a, double b) {
	return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1;
}
void debug() {
	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);
}

int arr[1001];

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n, cur, cnt = 0, mn = INT_MAX, t;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	sort(arr, arr+n);
	cur = arr[n-1];
	for (int i = 1; i <= cur; ++i) {
		cnt = 0;
		for (int j = 0; j < n; ++j) {
			if(arr[j] == i)
				continue;
			if(arr[j] > i) {
				cnt += arr[j] - (i + 1);
			} else {
				cnt += i - 1 - arr[j];
			}
		}
		if(cnt < mn) {
			mn = cnt;
			t = i;
		}
	}
	cout << t << " " << mn;
}
