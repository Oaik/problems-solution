#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define all(v)  	((v).begin()),((v).end())
#define sz(x)  		((ll) (x).size())
#define clr(a,b)	memset(a,b,sizeof(a))
const double EPS = 1e-8;
const double pi = acos(-1);
ll dcmp(double a, double b) {
	return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1;
}
void debug() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "rt", stdin);
//	freopen("output.in", "wt", stdout);
#endif
}

int const N = 1e3 + 9, M = 100 + 9, OO = 1e9;

bool isVisited[N], noo[N];

vector<int> vec;

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int n;
	bool no = 0;
	cin >> n;
	for (int i = 2; i <= n; ++i) {
		if(isVisited[i])
			continue;
		for (int j = i; j <= n; j += i) {
			if(!isVisited[j])
				isVisited[j] = 1;
			else
				noo[j] = 1;
		}
	}
	for (int i = 2; i <= n; ++i) {
		if(isVisited[i] && !noo[i])
			vec.push_back(i);
	}
	cout << vec.size() << "\n";
	for(auto it: vec)
		cout << it << " ";

	return 0;
}
