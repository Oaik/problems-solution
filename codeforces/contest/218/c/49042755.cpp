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

vector<vector<int>> vecX(1001), vecY(1001);
vector<pair<int, int>> pts;

bool visited[1001][1001] = {};
int cnt = 0;

void dfs(int x, int y) {
	if(visited[x][y])
		return;
	visited[x][y] = 1;
	for (int i = 0; i < sz(vecX[x]); ++i) {
		if(!visited[x][vecX[x][i]])
			dfs(x, vecX[x][i]);
	}
	for (int i = 0; i < sz(vecY[y]); ++i) {
		if(!visited[vecY[y][i]][y])
			dfs(vecY[y][i], y);
	}

}

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n, a, b;
		clr(visited, -1);
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> a >> b;
			vecX[a].push_back(b);
			vecY[b].push_back(a);
			visited[a][b] = 0;
			pts.push_back({a, b});
		}
		for (int i = 0; i < n; ++i) {
			if(!visited[pts[i].first][pts[i].second])
				dfs(pts[i].first, pts[i].second), ++cnt;
		}
		cout << cnt - 1;
		return 0;
}
