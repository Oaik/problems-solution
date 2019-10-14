#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define all(v)  	((v).begin()),((v).end())
#define sz(x)  		((int) (x).size())
#define clr(a,b)	memset(a,b,sizeof(a))

const double EPS = 1e-8;
int dcmp(double a, double b) {
	return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1;
}

void debug() {
	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);
}

vector<pair<int, int>> vec;
map<int, int> mpX, mpY;
map<pair<int, int>, int> mp;

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n, x, y;
	ll sum = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		sum += mpX[x] + mpY[y] - mp[{x,y}];
		mpX[x]++, mpY[y]++, mp[{x,y}]++;
		vec.push_back({x, y});
	}
	cout << sum;
}
