#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct edge {
	int from, to, w;
	edge(int from, int to, int w) : from(from), to(to), w(w) {}
	bool operator <(const edge &e) const {
		return e.w < w;
	}
};

int t, n, m, a, b, c;

vector<edge> schools;
int par[5000];
bool visited[5000][5000] = {0};

int find(int x) {
	if(x == par[x]) return x;
	return par[x] = find(par[x]);
}

pair<ll, vector<edge>> kruskal(int n) {
	ll minCost = 0;
	priority_queue<edge> q;
	vector<edge> ans;
	for (int i = 1; i <= n; ++i)
		par[i] = i;
	for (int i = 0; i < m; ++i){
		if(!visited[schools[i].from][schools[i].to])
			q.push(schools[i]);
	}
	while(!q.empty()) {
		edge e = q.top();q.pop();
		a = find(e.from), b = find(e.to);
		if (a != b) {
			ans.push_back(e);
			par[a] = b, --n, minCost += e.w;
			if(n == 1) return {minCost, ans};
		}
	}
	return {INT_MAX, ans};
}


int main() {
//	freopen("input.in", "r", stdin);
//	freopen("output.in", "w", stdout);
	cin >> t;
	while(t--) {
		cin >> n >> m;
		schools = vector<edge>();
		for (int i = 0; i < m; ++i) {
			cin >> a >> b >> c;
			schools.push_back(edge(a, b, c));
//			cin >> schools[i].from >> schools[i].to >> schools[i].w;
		}
		ll secMin = INT_MAX;
		pair<int, vector<edge>> ans;
		ans = kruskal(n);
		cout << ans.first << " ";
		for (int i = 0; i < (int)ans.second.size(); ++i) {
			visited[ans.second[i].from][ans.second[i].to] = 1;
			secMin = min(kruskal(n).first, secMin);
			visited[ans.second[i].from][ans.second[i].to] = 0;
		}
		cout << secMin;
		cout << "\n";
	}
	return 0;
}

