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
	//freopen("output.in", "wt", stdout);
#endif
}

int const N = 1e4 + 9, M = 100 + 9, OO = 5e8 + 9;

ll arr[N], mem[N][N];
int i;

ll dp(int x = 0, int prv = i) {
	if(x == i)
		return 0;
	ll& ret = mem[x][prv];
	if(~ret)
		return ret;
	ret = dp(x+1, prv);
	if(arr[x] > arr[prv])
		ret = max(ret, dp(x+1, x) + 1);
	return ret;
}

vector<ll> res;

void build(int x = 0, int prv = i) {
	if(x == i)
		return;
	if(dp(x, prv) == dp(x+1, prv))
		build(x+1, prv);
	else {
		res.push_back(arr[x]);
		build(x+1, x);
	}
}

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	string str;
	int t, n;
	cin >> t;
	cin.get();
	getline(cin, str);
	while(t--) {
		if(str == "") {
			i = 0;
			clr(mem, -1);
			while(getline(cin, str), str != "") {
				n = stoi(str);
				arr[i] = n;
				++i;
				if(cin.peek() == EOF)
					break;
			}
		}
		arr[i] = 0;
		res.clear();
		cout << "Max hits: " << dp() << "\n";
		build();
		for(auto it: res)
			cout << it << "\n";
		if(t)
			cout << "\n";
	}
	return 0;
}

