#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read(v) freopen(v, "rt", stdin);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, M = 1e6 + 1, OO = 1e9 + 1, MOD = 1e9 + 7;

int arr[N], dist[N];
vector<int> vec[N];

int n;

void BFS(int node) {
	queue<int> q;
	bool vis[N];
	clr(vis, 0);
	clr(dist, -1);
	vis[node] = 1;
	q.push(node);
	int sz, lvl = 0;
	while(!q.empty()) {
		sz = q.size();
		while(sz--) {
			int tp = q.front();
			q.pop();
			if(dist[tp] != -1)
				continue;
			dist[tp] = lvl;
			for(auto it: vec[tp]) {
				if(dist[it] != -1 || vis[it])
					continue;
				vis[it] = 1;
				q.push(it);
			}
		}
		++lvl;
	}
}

int main() {
//	fastIO
	read("jumping.in")
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", arr + i);
		for (int i = 0; i < n; ++i) {
			if(arr[i] + i < n)
				vec[arr[i] + i].push_back(i);
			if(i - arr[i] >= 0)
				vec[i - arr[i]].push_back(i);
		}
		BFS(n-1);
		for (int i = 0; i < n; ++i) {
			int val = dist[i];
			printf("%d\n", val);
			vec[i].clear();
		}
	}
	return 0;
}

