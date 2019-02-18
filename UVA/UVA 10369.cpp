#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct point {
	int from,to;
	double distance;
	point(int from, int to, double distance) : from(from), to(to), distance(distance){}
	bool operator < (const point &e) const {
		return e.distance < distance;
	}
};

vector<pair<int, int>> nodes;
vector<point> points;

double distance(pair<int, int> x, pair<int, int> y) {
	return sqrt((double)( (x.first - y.first) * (x.first - y.first) ) + (double)( (x.second - y.second) * (x.second - y.second) ));
}

vector<int> par(501);
vector<int> ranks(501);

int find(int x) {
	if (x == par[x]) return x;
	return par[x] = find(par[x]);
}

bool unionset(int x, int y) {
	x = find(x), y = find(y);
	if(x != y) {
		if(ranks[x] > ranks[y]) swap(x, y);
		par[x] = y;
		ranks[y]+=ranks[x];
	}
	return x != y;
}

int main() {

	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);
	int n;
	cin >> n;
	while(n--){
		int s, p, x, y;
		nodes.clear();
		points.clear();
		par.clear();
		ranks.clear();
		cin >> s >> p;
		for (int i = 1; i <= p; ++i) {
			cin >> x >> y;
			par[i] = i, ranks[i] = 1;
			nodes.push_back({x, y});
		}
		for (int i = 1; i <= p; ++i) {
			for (int j = i+1; j <= p; ++j) {
				points.push_back(point(i, j, distance(nodes[i-1], nodes[j-1])));
			}
		}
		cout << fixed << setprecision(2);
		int ptsz = (int)points.size();
		int z = 0;
		priority_queue<point> q;
		for (int i = 0; i < ptsz; ++i) {
			q.push(points[i]);
		}
		double val = 0.00;
		while(!q.empty()) {
			point pt = q.top();q.pop();
			if(unionset(pt.from, pt.to)) {
				++z;
				val = max(val, pt.distance);
				if(z == p-s) {
					cout << val << "\n";
					break;
				}
			}
		}

	}
}

