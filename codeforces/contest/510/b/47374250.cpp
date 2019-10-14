#include <bits/stdc++.h>

using namespace std;
#define ll long long

int n, m;
char arr[51][51];
bool visited[51][51];
int x, y;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

bool valid(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m;
}

vector<pair<int, int>> vec;
bool una = false;
bool done = false;
int num = 0;
void dfs(char a, int i, int j, int fromX, int fromY) {
	if(visited[i][j]) {
		done = true;
		return;
	}
	visited[i][j] = 1;
	for (int q = 0; q < 4; ++q) {
		if(valid(i + dx[q], j + dy[q]) && arr[i + dx[q]][j + dy[q]] == a) {
			if(i + dx[q] == fromX && j + dy[q] == fromY) continue;
			dfs(a, i + dx[q], j + dy[q], i, j);
		}
	}
}

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> m;
	int a, b;
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
		}
	}
	for (x = 0; x < n; ++x) {
		for (y = 0; y < m; ++y) {
			if(!visited[x][y]) {
				dfs(arr[x][y], x, y, -1, -1);
			}
			if(done) {
				cout << "Yes";
				return 0;
			}
		}
	}
	cout << "No";
}
