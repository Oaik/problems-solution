#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(),x.end()

const double EPS = 1e-8;
int dcmp(double a, double b) {
	return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1;
}

char arr[31][81];
bool visited[31][81];
char res;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool valid(int x, int y) {
	return x >= 0 && x < 80 && y >= 0 && y < 80;
}

void dfs(int x, int y) {
	if(visited[x][y])
		return;
	visited[x][y] = 1;
	for (int j = 0; j < 4; ++j) {
		if(valid(x + dx[j], y + dy[j]) && !visited[x + dx[j]][y + dy[j]] && arr[x + dx[j]][y + dy[j]] != '_' && arr[x + dx[j]][y + dy[j]] == ' ') {
			arr[x + dx[j]][y + dy[j]] = '#';
			dfs(x + dx[j], y + dy[j]);
		}
	}
}

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);
	int t, i = 0, n, j, startX, startY;
	bool found = false;
	string str, b;
	cin >> t;
	cin.get();
	while (t--) {
		i = 0;
		found = false;
		memset(visited, 0, sizeof(visited));
		cin.ignore(0);
		while (getline(cin,str)) {
			if (str[0] == '_') {
				b = str;
				break;
			}
			n = str.length();
			for (j = 0; j < n; ++j) {
				arr[i][j] = str[j];
				if(!found && str[j] != ' ' && str[j] != '*') {
					found = true;
					res = str[j];
				}
				if(str[j] == '*')
					startX = i, startY = j,arr[i][j] = '#';
			}
			for(; j < 80; ++j) {
				arr[i][j] = '_';
			}
			++i;
		}
		dfs(startX, startY);
		for (int x = 0; x < i; ++x) {
			for (int y = 0; y < 80; ++y) {
				if(arr[x][y] != '_')
					cout << arr[x][y];
			}
			cout << "\n";
		}
		cout << b << "\n";
	}
	return 0;
}
