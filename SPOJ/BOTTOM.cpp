#include <bits/stdc++.h>
using namespace std;
#define all(v) ((v).begin()),((v).end())
#define ll long long
#define fastIO cout << fixed << setprecision(12), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-12, PI = acos(-1);
const int N = 5e3 + 9, M = 1e6 + 9, OO = 1e9 + 7, MOD = 1e9 + 7, MOD2 = 998244353;
const ll INF = 2e18;
using namespace std;

vector<int> adj[N], vec;
vector<vector<int>> comps;
int lowlink[N], dfn[N], vid;
bool inStack[N];
stack<int> stk;

void tarjan(int node) {
	lowlink[node] = dfn[node] = ++vid;
	inStack[node] = 1;
	stk.push(node);
	for(auto it: adj[node]) {
		if(!dfn[it]) {
			tarjan(it);
			lowlink[node] = min(lowlink[node], lowlink[it]);
		} else if(inStack[node]) {
			lowlink[node] = min(lowlink[node], dfn[it]);
		}
	}
	if(dfn[node] == lowlink[node]) {
		int x = -1;
		vec.clear();
		while(x != node) {
			x = stk.top();
			inStack[x] = 0;
			vec.push_back(x);
			stk.pop();
		}
		comps.push_back(vec);
	}
}

int main() {
	fastIO;
#ifdef LOCAL
//	freopen("input.in", "rt", stdin);
#endif
	int n, m, u, v;
	while(cin >> n, n) {
		cin >> m;
		for (int i = 0; i < m; ++i) {
			cin >> u >> v;
			adj[u].push_back(v);
		}
		for (int i = 1; i <= n; ++i) {
			if(!dfn[i])
				tarjan(i);
		}
		set<int> vv;
		for(auto it: comps) {
			set<int> st;
			for(int ii: it)
				st.insert(ii);
			bool can = 1;
			for(int ii: it) {
				for(auto child: adj[ii]) {
					if(st.find(child) == st.end()) {
						can = 0;
						break;
					}
				}
			}
			if(can) {
				for(auto ii: it)
					vv.insert(ii);
			}
		}
		for(auto it: vv) cout << it << ' ';
		cout << '\n';
		for (int i = 1; i <= n; ++i) {
			adj[i].clear();
			dfn[i] = lowlink[i] = 0;
		}
		comps.clear();
	}
	return 0;
}

