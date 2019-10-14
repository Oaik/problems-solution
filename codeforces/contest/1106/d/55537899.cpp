#include <bits/stdc++.h>
using namespace std;
#define el      	'\n'
#define ft 			first
#define sd 			second
#define mp(x,y)  	make_pair((x),(y))
#define pb(x)    	push_back((x))
#define all(v)  	((v).begin()),((v).end())
#define sz(x)  		((int) (x).size())
#define clr(a,b)	memset(a,b,sizeof(a))
typedef long long ll;
void Yahia74() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
const int N = 1e5 + 74, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

vector<vector<int>> vec(N);
bool visited[N];
vector<int> ans;
void dfs(int x) {
	visited[x] = 1;
	ans.push_back(x);
	for (auto it : vec[x]) {
		if (!visited[it]) {
			visited[it] = 1;
			dfs(it);
		}
	}

}

int main() {
	Yahia74();
	int n, m, u, v;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> u >> v;
		if (u == v)
			continue;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i) {
		sort(all(vec[i]));
	}
	priority_queue<int , deque<int> , greater<int>> q;
	q.push(1);
	visited[1] = true ;
	while (!q.empty()) {
		int sz = q.size();
		while (sz--) {
			int u = q.top();
			q.pop();
			cout << u << ' ' ;
			for (int i = 0; i < sz(vec[u]); ++i) {
				int v = vec[u][i];
				if (!visited[v]) {
					visited[v] = true;
//					cout << v << ' ' ;
					q.push(v);
				}
			}
		}
	}
//	dfs(1);
//	for (auto it : ans)
//		cout << it << " ";
}
/*




























 */
