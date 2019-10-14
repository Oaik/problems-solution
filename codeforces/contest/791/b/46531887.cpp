#include <bits/stdc++.h>

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define clr(arr, k) (memset(arr, k, sizeof(arr)))
#define lpv(i,a,n) 	for(int i=a;i<(int)n;i++)
#define ll long long

using namespace std;

const double EPS = (1e-8);
const double PI = acos(-1.0);
const ll INF = 1e9;

int dcmp(double x, double y) {
	return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}
void contest() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);
#endif
}

using namespace std;

bool visited[150001];
vector<vector<int>> vec;

bool dfs(int x) {
	visited[x] = 1;
	int mySize = sz(vec[x]);
	for (int i = 0; i < sz(vec[x]); ++i) {
		if(sz(vec[vec[x][i]]) != mySize) {
			cout << "NO";
			return false;
		}
	}
	for (int i = 0; i < sz(vec[x]); ++i)
		vec[vec[x][i]].pop_back();
//		vec[vec[x][i]].erase(vec[vec[x][i]].begin());
	return true;
}

int main() {
	int n, m;
	cin >> n >> m;
	vec = vector<vector<int>>(n+1);
	int a, b;
	bool ok = true;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	for (int i = 0; i < n; ++i) {
		sort(vec[i].begin(), vec[i].end(), std::greater<int>() );
	}
	for (int i = 1; i <= n && ok; ++i) {
		if(!visited[i])
			ok = dfs(i);
	}
	if(ok)
		cout << "YES";
	return 0;
}
