#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define all(v)  	((v).begin()),((v).end())
#define sz(x)  		((int) (x).size())
#define clr(a,b)	memset(a,b,sizeof(a))
const double EPS = 1e-8;
const double pi = acos(-1);

int dcmp(double a, double b) {
	return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1;
}
void debug() {
	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);
}

const int N = 1000001, M = 2000002 ;
int ne, t, n, m, u, v, to[M], nxt[M], head[N];
int visited[N];
vector<int> vec;
int arr[50009];

void init() {
	ne = 0;
	memset(head, -1, sizeof head);
	clr(visited, 0);
}

void addEdge(int f, int t) {
	nxt[ne] = head[f];
	to[ne] = t;
	head[f] = ne++;
}

void addBiEdge(int f, int t) {
	addEdge(f, t);
	addEdge(t, f);
}


void DFS(int node, int par) {
	arr[node] = par;
	visited[node] = 1;
	for(int i = head[node]; ~i; i = nxt[i]) {
		if(!visited[to[i]]) {
			DFS(to[i], node);
		}
	}
}

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n, r1, r2, u;
	cin >> n >> r1 >> r2;
	init();
	--r1, --r2;
	for (int i = 0; i < n; ++i) {
		cin >> u;
		--u;
		if(i == r1) {
			i++;
		}
		addBiEdge(i, u);
	}
	DFS(r2, -1);
	for (int i = 0; i < n; ++i) {
		if(arr[i] != -1)
			cout << arr[i] + 1 << " ";
	}
}
