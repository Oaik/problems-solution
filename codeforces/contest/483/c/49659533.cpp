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

ll const N = 1e5 + 9, M = N * N / 2, OO = 0x3f3f3f3f;
vector<ll> vec;
bool visited[N];

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	ll n, k, prev, cnt = 1;
	cin >> n >> k;
	visited[n], prev = n;
	vec.push_back(n);
	while (cnt < n && prev != 0) {
		if (prev + k < n && !visited[prev + k]) {
			vec.push_back(prev + k);
			visited[prev + k] = 1;
			prev += k;
			if(k != 1)
				--k;
		} else if (prev - k > 0 && !visited[prev - k]) {
			vec.push_back(prev - k);
			visited[prev - k] = 1;
			prev -= k;
			if(k != 1)
				--k;
		} else {
			--prev;
		}
	}
	for(auto it: vec)
		cout << it << " ";
	return 0;
}
