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

int const N = 50 + 9, M = 100 + 9, OO = 1e9;

bool arr[N][N];

int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
int n, r1, r2, c1, c2;
bool valid(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < n;
}
bool visited[N][N];
vector<pair<int, int>> vecS, vecX;

void DFS(int r = r1, int c = c1) {
	visited[r][c] = 1;
	vecS.push_back({r, c});
	for (int i = 0; i < 4; ++i) {
		int nr = r+dx[i], nc = c+dy[i];
		if(valid(nr, nc) && !visited[nr][nc] && !arr[nr][nc]) {
			DFS(nr, nc);
		}
	}
}
void DFS2(int r = r2, int c = c2) {
	visited[r][c] = 1;
	vecX.push_back({r, c});
	for (int i = 0; i < 4; ++i) {
		int nr = r+dx[i], nc = c+dy[i];
		if(valid(nr, nc) && !visited[nr][nc] && !arr[nr][nc]) {
			DFS2(nr, nc);
		}
	}
}

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	cin >> n >> r1 >> c1 >> r2 >> c2;
	--r1, --c1, --r2, --c2;
	char a;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a;
			if(a == '0')
				arr[i][j] = 0;
			else
				arr[i][j] = 1;
		}
	}
	DFS(r1, c1);
//	for(auto it: vecS) {
//		cout << it.first << " " << it.second << "\n";
//	}
	if(visited[r2][c2]) {
		cout << 0;
		return 0;
	}
	DFS2();
	int mxNum = 1e9;
	for(auto jj: vecS) {
		for(auto it: vecX) {
			mxNum = min(mxNum, (jj.first - it.first) * (jj.first - it.first) + (jj.second - it.second) * (jj.second - it.second));
		}
	}
	cout << mxNum;
	return 0;
}
