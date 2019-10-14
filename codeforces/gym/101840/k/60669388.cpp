#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read(v) freopen(v, "rt", stdin);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e6 + 9, M = 1e6 + 1, OO = 1e9 + 1;
const long long MOD = 1e9 + 7;

int main() {
	fastIO
	read("katryoshka.in")
//	read("input.in")
	int T,
	n, m, k, x, ans = 0, cases = 0;
	cin >> T;
	while (T--) {
		ans = 0;
		cin >> n >> m >> k;
		x = min(n, min(m, k));
		ans += x, n -= x, m -= x, k -= x;

		x = min(n / 2, min(m, k));
		ans += x, n -= 2 * x, m -= x, k -= x;

		x = min(n / 2, k);
		ans += x, n -= 2 * x, k -= x;

		cout << "Case " << ++cases << ": " << ans <<el;
	}
//	int mx = 1e8, gg = 0;
//	for (int i = 10; i <= mx; ++i) {
//		string str = to_string(i);
//		string res1 = str.substr(0, str.size() / 2);
//		string res2 = str.substr(str.size() / 2);
//		if(__gcd(stoi(res1), stoi(res2)) > 1)
////			cout << str << endl;
//			++gg;
//	}
//	cout << gg;
	return 0;
}

