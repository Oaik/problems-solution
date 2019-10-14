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

int const N = 1e5 + 9, M = 100 + 9, OO = 5e8 + 9;
double di1, di2;
double dist(int x1, int y1, int x2, int y2) {
	return sqrt((x1-x2) * (x1-x2) + (y1-y2) * (y1-y2));
}

bool visitedX[101], visitedY[101];

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	vector<pair<int, int>> vec, ans;
	int n,m;
	cin >> n >> m;
	int i = 0, j = m;
	while(i != n + 1 && j != -1) {
		ans.push_back({i, j});
		++i, --j;
	}

	cout << ans.size() << "\n";
	for(auto it: ans) {
		cout << it.first << " " << it.second << "\n";
	}
	return 0;
}
