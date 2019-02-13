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

int const N = 2e4 + 9, M = 500, OO = 5e8 + 9;

vector<vector<int>> adjMat;
int t, n, m, s, e, x, y, w;

struct edge {
	int from, to, w;
	edge(int from, int to, int w) :
		from(from), to(to), w(w) {}
	bool operator < (const edge &e) const {
		return w > e.w;
	}
};

vector<vector<edge>> edgeList;

int Dijkstra(int start, int end) {
	vector<int> dist(n+1, OO);
	dist[start] = 0;

	priority_queue<edge> q;
	q.push({-1, start, 0});

	while(!q.empty()) {

		edge e = q.top();
		q.pop();

		if(e.w > dist[e.to]) continue;

		int n = sz(edgeList[e.to]);
		for (int i = 0; i < n; ++i) {
			edge ne = edgeList[e.to][i];
			if(dist[ne.to] > dist[ne.from] + ne.w) {
				ne.w = dist[ne.to] = dist[ne.from] + ne.w;
				q.push(ne);
			}
		}
	}

	return dist[end];
}


int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int idx = 0, val;
	cin >> t;
	while (t--) {
		cin >> n >> m >> s >> e;
		edgeList = vector<vector<edge>>(n+1);
		for (int i = 0; i < m; ++i) {
			cin >> x >> y >> w;
			edgeList[x].push_back({x, y, w});
			edgeList[y].push_back({y, x, w});
		}
		val = Dijkstra(s, e);
		cout << "Case #" << ++idx << ": ";
		if (val == OO)
			cout << "unreachable\n";
		else
			cout << val << "\n";
	}
	return 0;
}

