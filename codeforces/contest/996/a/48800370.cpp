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

int d[] = {100, 20, 10, 5, 1};

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n, cnt = 0, cur = 0;
	cin >> n;
	while(n) {
		for (int i = cur; i < 5; ++i) {
			if(n - d[i] >= 0) {
				n -= d[i];
				cnt++;
				cur = i;
				break;
			}
		}
	}
	cout << cnt;
}
