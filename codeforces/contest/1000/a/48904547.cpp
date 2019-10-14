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

map<string, int> mp;

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n, cnt = 0;
	string s;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		mp[s]++;
	}
	for (int i = 0; i < n; ++i) {
		cin >> s;
		if(mp[s] > 0) {
			--mp[s];
		} else {
			++cnt;
		}
	}
	cout << cnt;
}
