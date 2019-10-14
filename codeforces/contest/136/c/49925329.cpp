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

int const N = 1e5+9, M = 500, OO = 5e8 + 9;

vector<int> vec;

int arr[9];

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int n, a;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		if(a == 1)
			++arr[a];
		vec.push_back(a);
	}
	if(arr[1] == n) {
		--n;
		for (int i = 0; i < n; ++i) {
			cout << 1 << " ";
		}
		cout << 2;
		return 0;
	}
	sort(vec.begin(), vec.end());
	cout << 1;
	--n;
	for (int i = 0; i < n; ++i) {
		cout << " " << vec[i];
	}
	return 0;
}
