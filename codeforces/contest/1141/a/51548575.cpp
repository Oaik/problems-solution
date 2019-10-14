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

int const N = 5e8 + 9, M = 100 + 9, OO = 1e9;

int main() {
	cout << fixed << setprecision(12);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int n, m;
	cin >> n >> m;
	queue<int> q;
	q.push(m);
	int lvl = 0, sz = 0, cur;
	while(!q.empty()) {
		++lvl, sz = q.size();
		while(sz--) {
			cur = q.front();
			q.pop();
			if(cur == n) {
				cout << lvl-1;
				return 0;
			}
			if(cur % 2 == 0)
				q.push(cur/2);
			if(cur % 3 == 0)
				q.push(cur/3);
		}
	}
	cout << -1;
}