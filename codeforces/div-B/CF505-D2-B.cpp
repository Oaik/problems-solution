#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <vector>
//#include "gemo.h"

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
void contest() {
	#ifndef ONLINE_JUDGE
		freopen("input.in", "r", stdin);
		freopen("output.in", "w", stdout);
	#endif
}

int visited[101][101] = {0}, n;
int counter = 0;
vector<vector<pair<int, int>>> vec;

int dfs(int start, int end, int c) {
	if (visited[start][c])
		return 0;
	visited[start][c] = 1;
	if (start == end)
		counter++;
	for(auto i: vec[start]) {
		if(!visited[i.first][i.second] && i.second == c ) {
			dfs(i.first, end, i.second);

		}
	}
	return 0;
}

using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int m, a, b, c;
	cin >> n >> m;
	vec = vector<vector<pair<int, int>>>(n+1);

	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		vec[a].push_back({b, c});
		vec[b].push_back({a, c});
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		counter = 0;
		clr(visited, 0);
		cin >> a >> b;
		for(auto j: vec[a])
			dfs(a, b, j.second);
		cout << counter << "\n";
	}
}

