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
	read("lazy.in")
//	read("input.in")
	int t,n, ans;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		ans = 0;
		while (n != 1) {
			if (n % 2 == 0) {
				ans += n / 2;
				n /= 2;
			} else {
				ans += n / 2;
				n /= 2;
				n++;
			}
		}
		//n++;
		cout << "Case " << i << ": " << ans << el;
	}
	return 0;
}

