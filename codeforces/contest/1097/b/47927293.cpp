#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define all(v)  	((v).begin()),((v).end())
#define sz(x)  		((int) (x).size())
#define clr(a,b)	memset(a,b,sizeof(a))

const double EPS = 1e-8;
int dcmp(double a, double b) {
	return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1;
}

void debug() {
	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);
}

int deg[16] = {}, sz, a, cnt = 0, n;
bool done = false, ok = false;
queue<int> q;
void bfs(int dg) {
	while(!q.empty() && !ok && dg < n) {
		sz = q.size();
		while(sz--) {
			a = q.front();
			q.pop();
			q.push(a + deg[dg]);
			q.push(a - deg[dg]);
		}
		++dg;
	}
}

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> deg[i];
	}
	q.push(deg[0]);
	q.push(-deg[0]);

	bfs(1);
	int it;
	while(!q.empty()) {
		it = q.front();
		q.pop();
		if(it % 360 == 0 || it == 0) {
			done = true;
			break;
		}
	}
	if(done) {
		cout << "YES";
	} else {
		cout << "NO";
	}
	return 0;
}
