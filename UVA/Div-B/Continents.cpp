#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<numeric>
#include<utility>
#include<functional>
#include<stdio.h>
#include<assert.h>
#include<memory.h>
#include<bitset>
#include <unordered_map>
using namespace std;

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define clr(arr, k) (memset(arr, k, sizeof(arr)))
#define lpv(i,a,n) 	for(int i=a;i<(int)n;i++)
#define ll long long

const double EPS = (1e-7);
const ll INF = 1e9;

int dcmp(double x, double y) {
	return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

void contest() {
	freopen("input.in", "r", stdin);
}

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int m, n, x, y, cnt = 0, lands = 0;
char land, water;
string space;
char arr[21][21];
bool visited[21][21];

bool valid(int x, int y) {
	return x >= 0 && x < m && y >= 0 && y < n;
}

int dfs(int x, int y) {
	if (visited[x][y])
		return 0;
	visited[x][y] = 1;
	++lands;
	if (y == n-1 && !visited[x][0] && arr[x][0] == land ) {
		dfs(x, 0);
	}
	if (y == 0 && !visited[x][n-1] && arr[x][n-1] == land ) {
		dfs(x, n-1);
	}
	for (int i = 0; i < 4; ++i) {
		if (valid(x + dx[i], y + dy[i]) && arr[x + dx[i]][y + dy[i]] == land && !visited[x + dx[i]][ y + dy[i]]) {
			dfs(x + dx[i], y + dy[i]);
		}
	}

	return lands;
}

int main() {
	bool found = false;
	while (cin >> m >> n) {
		y = 0, x = 0;
		land = water = '\0';
		found = false;
//		if (n == 1 && m == 1) {
//			cout << 0;
//			continue;
//		}

		memset(visited, 0, sizeof(visited));
		memset(arr, '\0', sizeof(arr));

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> arr[i][j];
			}
		}

		cin >> y >> x;
		land = arr[y][x];

		dfs(y, x);
		cnt = 0, lands = 0;

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (arr[i][j] == land && !visited[i][j]) {
					cnt = max(cnt, dfs(i, j));
					lands = 0;
				}
			}
		}

		cout << cnt << "\n";
	}
	return 0;
}

