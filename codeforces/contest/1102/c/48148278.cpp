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

vector<int> q;

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n, x, y, a;
	cin >> n >> x >> y;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		q.push_back(a);
	}
	bool me = x > y;
//	int start = 0, end = INT_MAX - 1,
	int zeros = 0, curr;
	while(!q.empty()) {
		sort(q.rbegin(), q.rend());
		curr = q.back();q.pop_back();
		curr -= x;
		if(curr <= 0) {
			++zeros;
			if(!q.empty())
				q[q.size() - 1] += y;
			continue;
		}
		if(!me) {
			break;
		}
		++zeros;
	}
	cout << zeros;
}
