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
	//freopen("output.in", "wt", stdout);
#endif
}

int const N = 101, M = 100 + 9, OO = 1e9;

int arr[N], res[N];
map<int , bool> mp;

deque<int> q;

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	sort(arr, arr+n);
	int last = n-1, first = n-2, i = 0, j = n-1;
	while(first >= 0) {
		if(first >= 0)
			res[i] = arr[first];
		if(last >= 0)
			res[j] = arr[last];
		last -= 2, first -= 2;
		++i, --j;
		if(i == j)
			break;
	}
	if(n % 2 == 1)
		res[n/2] = arr[0];
	for (int k = 0; k < n; ++k) {
		cout << res[k] <<  " ";
	}
	return 0;
}
