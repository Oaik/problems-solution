#include <bits/stdc++.h>
using namespace std;

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define clr(arr, k) (memset(arr, k, sizeof(arr)))
#define lpv(i,a,n) 	for(int i=a;i<(int)n;i++)
#define ll long long

const double EPS = (1e-7);
const ll INF = 1e9;

void contest() {
	#ifndef ONLINE_JUDGE
		freopen("input.in", "r", stdin);
		freopen("output.in", "w", stdout);
	#endif
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	double n, rx, ry, x, y;
	set<double> points;
	ll total = 0;
	bool foundX = false, foundY = false;
	cin >> n >> rx >> ry;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		if (x == rx) {
			if(!foundX)
				foundX = true, total++;
		} else if (y == ry) {
			if(!foundY)
				foundY = true, total++;

		} else {
			points.insert((x-rx) / (y-ry));
		}
	}
	cout << total + points.size();
	return 0;
}

