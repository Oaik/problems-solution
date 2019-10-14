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

map<char, int> mp;

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n, k, cnt = 1;
	char a, b = ';';
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		if(a == b) {
			++cnt;
			if(cnt == k) {
				mp[a]++;
				cnt = 0;
			}
		} else {
			cnt = 1;
		}
		if(cnt >= k) {
			mp[a]++;
			cnt = 0;
		}
		b = a;
	}
	int mx = 0;
	for(auto it: mp) {
		mx = max(mx, it.second);
	}
	cout << mx;
}
