
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, M = 2e5 + 5, OO = 0x3f3f3f3f;

int head[N], nxt[M], to[M], cost[M], ne, par[N];
int n = 128, m, c, u, v;
map<pair<int, int>, int> maj;

void init() {
	memset(head, -1, sizeof head);
	ne = 0;
	maj.clear();
}

void addEdge(int f, int t, int c) {
	nxt[ne] = head[f];
	to[ne] = t;
	cost[ne] = c;
	head[f] = ne++;
}

void addBiEdge(int a, int b, int c) {
	addEdge(a, b, c);
	addEdge(b, a, c);
}

int dis[N];
int DijkstraELOGE(int src, int lwst) {
	priority_queue<pair<int, int> > q;
	int ans = -1;
	q.push( { 0, src });
	memset(dis, OO, sizeof dis);
	dis[src] = 0;
	while (q.size()) {
		if(ans == -1)
			ans = 0;
		int u = q.top().second, d = -q.top().first;
		q.pop();
		if (d > dis[u])
			continue;
		for (int k = head[u]; ~k; k = nxt[k]) {
			int v = to[k], c = cost[k];
			int dd = d + c;
			if (dis[v] > dd && maj[{v, u}] <= lwst) {
				dis[v] = dd;
				q.push( { -dd, v });
				ans = max(ans, maj[{v, u}]);
			}
		}
	}
	return ans;
}

int main() {
	int t, qq, mmm, ans = 0;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d%d", &n, &m, &qq);
		init();
		while (m--) {
			scanf("%d%d%d%d", &u, &v, &c, &mmm);
			addBiEdge(u, v, c);
			maj[ { u, v }] = mmm;
			maj[ { v, u }] = mmm;
		}
		ans = -1;
		int hi = 1000000001, lw = 1, mid, aaa;
		while(hi > lw) {
			mid = hi - (hi-lw)/2;
			aaa = DijkstraELOGE(1, mid);
			if( aaa != -1 && dis[n] < qq) {
				hi = mid - 1;
				ans = aaa;
			} else {
				lw = mid+1;
			}

		}
		if(ans == -1) {
			printf("%d\n", -1);
		} else {
			printf("%d\n", ans);
		}
	}
	return 0;
}
