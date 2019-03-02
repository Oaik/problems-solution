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
	freopen("output.in", "wt", stdout);
#endif
}

int const N = 1e5 + 9, M = 100 + 9, OO = 1e9;

ll arr[1009][19000];
bool isA[1009][19000];
vector<vector<pair<ll, ll>>> vec;
vector<pair<ll, ll>> pos;

ll pw(ll x, ll y) {
	ll res = 1;
	if(y == 0)
		return 1;
	for (int i = 0; i < y; ++i) {
		res *= x;
	}
	return res;
}

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	string str, res, rep;
	ll t, n, m, x, lt, num, idx = 0, cnt = 0, sum = 0, numIdx = 0;
	bool lsa = 1;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		vec = vector<vector<pair<ll, ll>>>(1e5);
		clr(arr, 0);
		clr(isA, 0);
		pos.clear();
		cnt = 0;
		for (ll i = 1; i <= m; ++i) {
			for (ll j = 1; j <= n; ++j) {
				cin >> str;
				if(str[0] != '=')
					arr[i][j] = stoll(str);
				else {
					x = str.length(), idx = 0, lt = 0, num = 0, res = "", numIdx = 0, rep = "";
					for (ll k = 1; k < x; ++k) {
						if(str[k] >= 'A') {
							res = str[k] + res;
							++idx;
						} else if(str[k] == '+') {
							for (ll y = 0; y < idx; ++y) {
								lt += pw(26, y) * (res[y] - 'A' + 1);
							}
							num = stoll(rep);
							vec[cnt].push_back({num, lt}); // row & col
							idx = 0, lt = 0, num = 0, numIdx = 0, res = "", rep = "";
						} else {
//							num += pw(10, numIdx) * (str[k] - '0' + 1) - 1;
							rep += str[k];
							++numIdx;
						}
					}
					for (ll y = 0; y < idx; ++y) {
						lt += pw(26, y) * (res[y] - 'A' + 1);
					}
					num = stoll(rep);
					vec[cnt].push_back({num, lt});
					pos.push_back({i, j});
					++cnt;
					isA[i][j] = 1;
				}
			}
		}
		bool can = 0;
		for (ll j = 0; j <= cnt; ++j) {
			lsa = 0;
			for (ll i = 0; i < cnt; ++i) {
				can = 0;
				if(!isA[pos[i].first][pos[i].second])
					continue;
				x = vec[i].size(), sum = 0;
				for(auto it: vec[i]) {
					if(isA[it.first][it.second]) {
						can = 1;
						break;
					}
					sum += arr[it.first][it.second];
				}
				if(!can) {
					arr[pos[i].first][pos[i].second] = sum;
					isA[pos[i].first][pos[i].second] = 0;
					lsa = 1;
				}
			}
			if(!lsa)
				break;
		}
		for (ll i = 1; i <= m; ++i) {
			cout << arr[i][1];
			for (ll j = 2; j <= n; ++j) {
				cout << " " << arr[i][j];
			}
			cout << "\n";
		}
	}
}

