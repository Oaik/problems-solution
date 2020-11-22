#include <bits/stdc++.h>
#define ll long long
#define SZ(vvv) ((int)vvv.size())
#define FOR(i,initVal,n) for(int i = initVal;i < int(n);i++)
#define RFOR(i, initVal,n) for(int i = initVal;i > int(n);i--)
#define ALL(vvv) vvv.begin(), vvv.end()
#define RALL(vvv) vvv.rbegin(), vvv.rend()
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;
const int N = 3e5 + 9, M = 1e2 + 3, MOD = 1e9 + 7, LEN = 650;

ll arr[N];
vector<ll> vec[LEN];

void runtestcase() {
	ll n, m, u, p, l, r, UU;
	cin >> n >> m >> UU;
	for(int i = 0; i < n; ++i) {
		cin >> arr[i];
		vec[i / LEN].push_back(arr[i]);
	}
	for(int i = 0; i <= n / LEN; ++i)
		sort(vec[i].begin(), vec[i].end());
	while(m--) {
		cin >> l >> r >> u >> p;
		--l, --r, --p;
		ll cl = l / LEN, cr = r / LEN, k = 0;
		if(cl == cr) {
				for(int i = l; i <= r; ++i) 
					k += arr[i] < u;
		} else {
			for(int i = l, end = (cl + 1) * LEN - 1; i <= end; ++i)
				k += arr[i] < u;
			for(int i = cl + 1; i < cr; ++i) {
				k += upper_bound(ALL(vec[i]), u - 1) - vec[i].begin();
			}
			for(int i = cr * LEN; i <= r; ++i)
				k += arr[i] < u;
		}
		ll nwVal = UU * k / (r - l + 1);
		int cp = p / LEN;
		vec[cp].erase(lower_bound(ALL(vec[cp]), arr[p]));
		arr[p] = nwVal;
		vec[cp].insert(upper_bound(ALL(vec[cp]), nwVal), nwVal);
	}
	for(int i = 0; i < n; ++i)
		cout << arr[i] << '\n';
}

int main() {
#ifdef LOCAL
//  freopen("input.in", "rt", stdin);
#endif
  fastIO;
  int t = 1, tt = 1;
  //cin >> t;
  while(t) {
//		cout << "Case #" << tt << ':' << ' ';
	runtestcase();
	--t, ++tt;
  }
}

