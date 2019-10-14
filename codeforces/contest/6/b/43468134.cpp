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

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define ll long long

const double EPS = (1e-7);
int dcmp(double x, double y) {
	return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}

using namespace std;

int n, m, counter = 0;
int visited[27], dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
char arr[100][100];
char c;

bool valid(int x, int y) {
	return x < n && x >= 0 && y < m && y >= 0;
}

void dfs(int x, int y) {
	visited[arr[x][y] - 'A'] = 1;
	for (int i = 0; i < 4; ++i) {
		if (!visited[arr[x+dx[i]][y+dy[i]] - 'A'] && arr[x+dx[i]][y+dy[i]] != '.' && arr[x+dx[i]][y+dy[i]] != '\0' && valid(x+dx[i],y+dy[i])) {
			visited[arr[x+dx[i]][y+dy[i]] - 'A'] = 1;
			++counter;
		}
	}
}

int main() {
	multimap<int,int> pre;
	cin >> n >> m >> c;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == c) {
				pre.emplace(i, j);
			}
		}
	}
	multimap<int,int>::iterator it = pre.begin();
	for (; it!=pre.end(); ++it) {
		dfs(it->first, it->second);
	}
	cout << counter;
}
