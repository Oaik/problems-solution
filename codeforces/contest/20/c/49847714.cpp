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

ll const N = 1e5 + 9, M = 500, OO = 100000000009;

struct edge {
	int from, to;
	ll w;

	edge(int f, int t, ll c) :
		from(f), to(t), w(c) {}

	bool operator < (const edge &e) const {
		return w > e.w;
	}
};

int prevv[N];
vector<vector<edge>> ed(N);

ll Dijkstra(int start, int end) {
	vector<ll> dist(N, OO);
	dist[0] = 0;

	priority_queue<edge> q;
	q.push({-1, 0, 0});
	int n;
	while(!q.empty()) {
		edge e = q.top();
		q.pop();

		if(dist[e.to] < e.w) continue;

		prevv[e.to] = e.from;
		n = sz(ed[e.to]);
		for (int j = 0; j < n; ++j) {
			edge ne = ed[e.to][j];
			if(dist[ne.to] > dist[ne.from] + ne.w) {
				ne.w = dist[ne.to] = dist[ne.from] + ne.w;
				q.push(ne);
			}
		}
	}

	return dist[end];
}

void build(int end) {
	if(prevv[end] != -1) build(prevv[end]);
	else return;
	cout << prevv[end] + 1 << " ";
}

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int n, m, u , v, c;
	ll val;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> u >> v >> c;
		--u, --v;
		ed[u].push_back({u, v, c});
		ed[v].push_back({v, u, c});
	}
	val = Dijkstra(0, n-1);
	if(val == OO) {
		cout << "-1\n";
	} else {
		build(n-1);
		cout << n;
		cout << "\n";
	}
	return 0;
}
