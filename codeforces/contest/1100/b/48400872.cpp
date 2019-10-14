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

int arr[100001] = {};
bool vis[100001] = {};

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n, m, a, req = 0;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> a;
		arr[a]++;
		if(!vis[a]) {
			++req, vis[a] = 1;
		}
		if(req == n) {
			cout << '1';
			for (int j = 1; j <= n; ++j) {
				arr[j]--;
				if(arr[j] == 0)
					vis[j] = 0, --req;
			}
		} else
			cout << '0';
	}
}
