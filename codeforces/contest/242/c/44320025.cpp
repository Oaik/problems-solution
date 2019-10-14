#include <bits/stdc++.h>
using namespace std;

#define all(v)			((v).begin()), ((v).end())
#define sz(v)			((int)((v).size()))
#define clr(v, d)		memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lp(i, n)		for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)
typedef long long ll;

set<pair<int, int>> points;

int main() {
	std::ios_base::sync_with_stdio(false);
	int s1, s2, e1, e2, n, r, a, b;
	cin >> s1 >> s2 >> e1 >> e2 >> n;
	for (int i = 0; i < n; ++i) {
		cin >> r >> a >> b;
		for (int i = a; i <= b; ++i)
			points.insert(make_pair(r, i));
	}
	queue<pair<int, int>> q;
	map<pair<int, int>, int> mp;
	pair<int, int> se = {s1, s2};
	int dx[] = { 0, 0, -1, 1, -1, 1, 1, -1 };
	int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
	int currX, currY;
	q.push(se);
	int sz = 1, dep = 0;
	for (; !q.empty(); sz=q.size(), dep++) {
		while(sz--) {
			se = q.front(); q.pop();
			for (int i = 0; i < 8; ++i) {
				currX = se.first + dx[i];
				currY = se.second + dy[i];
				auto p = std::make_pair(currX, currY);
				if ( points.count(p) == 0 ||  mp.count(p) != 0 ) {
					continue;
				}
				if (currX == e1 && currY == e2) {
					cout << dep + 1;
					return 0;
				}
				q.push(p);
				mp[p] = dep+1;
			}
		}
	}
	cout << -1;
}
