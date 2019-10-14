#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>

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
using namespace std;

int visited[101];
vector<vector<int>> vec;

void dfs(int x) {
	if (visited[x])
		return ;
	visited[x] = 1;
	for(auto i: vec[x]) {
		if(!visited[i])
			dfs(i);
	}
	return ;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n, m, a, b = 0;
	cin >> n >> m;
	vec = vector<vector<int>> (n+1);
	set<int> st;
//	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		st.insert(a); st.insert(b);
		vec[b].push_back(a);
		vec[a].push_back(b);
	}
	ll res = 1LL << n;
	for (int i = 1; i <= n; ++i) {
		if(!visited[i]) {
			dfs(i);
			res >>= 1;
		}
	}
	cout << (res);
}
