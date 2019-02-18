#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(),x.end()

const double EPS = 1e-8;
int dcmp(double a, double b) {
	return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1;
}

struct node {
	string from, to;
	int cost;
	node(string from, string to, int cost) : from(from), to(to), cost(cost) {}
	bool operator <(const node &n) const {
		return cost > n.cost;
	}
};

map<string, string> mp;
map<string, ll> ranks;
priority_queue<node> q;

string find(string node) {
	if(node == mp[node]) return node;
	return mp[node] = find(mp[node]);
}

bool link(string from, string to) {
	from = find(from), to = find(to);
	if(from != to) {
		if(ranks[from] < ranks[to]) swap(from, to);
		mp[from] = to;
		ranks[from]++;
	}
	return from != to;
}

ll totalCost = 0;

ll kruskal(int n) {
	while(!q.empty()) {
		node e = q.top(); q.pop();
		if(link(e.from, e.to)) {
			totalCost += e.cost;
			--n;
			if(n == 1) return totalCost;
		}
	}
	return totalCost;
}

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);
	bool f = false;
	int t,n, m, cost;
	string from, to;
	cin >> t;
	while(t--) {
		if(f)
			cout << "\n";
		else
			f = true;
		mp.clear();ranks.clear();q =priority_queue<node>();totalCost = 0;
		cin >> n >> m;
		for (int i = 0; i < m; ++i) {
			cin >> from >> to >> cost;
			mp[from] = from,mp[to] = to, ranks[from] = 1, ranks[to] = 1;
			q.push(node(from, to, cost));
		}
		cout << kruskal(n) << "\n";
	}
	return 0;
}
