#include <bits/stdc++.h>

using namespace std;
#define ll long long
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

bool arr[N];

int main() {
	cout << fixed << setprecision(5);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	bool can = 0;
	for (int i = 1; i < n; ++i) {
		if(n % i != 0 || (n/i) < 3)
			continue;
		for (int k = 0; k < i; ++k) {
			can = 0;
			for (int j = k; j < n; j += i) {
				if(!arr[j])
					can = 1;
				if(can)
					break;
			}
			if(!can) {
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
	return 0;
}
