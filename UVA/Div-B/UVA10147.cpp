#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct edge{
	int from, to, w;
	edge( int from, int to, int W ): from(from), to(to), w(W) {}
	bool operator<( const edge& e ) const{
		return e.w < w;
	}
};

vector<pair<int, int>> pts(800);
int par[800] = {};
int t, n, m, a, b, cnt = 0;

int findPar(int x) {
	if(par[x] == x) return x;
	return par[x] = findPar(par[x]);
}

bool kruskal() {
//	ans = vector<edge>();
	priority_queue<edge> q;
	for (int i = 1; i < n; ++i) {
		for (int j = i+1; j <= n; ++j) {
			if(findPar(i) != findPar(j)) {
				q.push(edge(i, j, (pts[i].first - pts[j].first) * (pts[i].first - pts[j].first) + (pts[i].second - pts[j].second) * (pts[i].second - pts[j].second)));
			}
		}
	}
	while(!q.empty()) {
		const edge& ed = q.top();
		a = findPar(ed.from), b = findPar(ed.to);
		if(a != b) {
			par[a] = b;
			cout << ed.from << " " << ed.to << "\n";
			++cnt;
		}
		if(cnt == n-1) return true;
		q.pop();
	}
	return false;
}

int main() {
	cin >> t;
	while(t--) {
		cnt = 0;
		cin >> n;
		pts = vector<pair<int, int>>(800);
		for (int i = 1; i <= n; ++i) {
			cin >> pts[i].first >> pts[i].second;
			par[i] = i;
		}
		cin >> m;
		for (int i = 1; i <= m; ++i) {
			cin >> a >> b;
			a = findPar(a), b = findPar(b);
			if(a != b) {
				par[a] = b;
				++cnt;
			}
		}
		if(cnt == n-1) {
			cout << "No new highways need\n";
		} else {
			if(!kruskal()) {
				cout << "No new highways need\n";
			}
		}
		if(t)
			cout << "\n";
	}
	return 0;
}

