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

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int q, l1, r1, l2, r2;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		cin >> l1 >> r1 >> l2 >> r2;
		cout << l1 << " ";
		if(l1 != l2) {
			cout << l2;
		} else {
			cout << r2;
		}
		cout << "\n";
	}
}
