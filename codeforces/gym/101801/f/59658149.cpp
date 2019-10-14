#include <bits/stdc++.h>
using namespace std;
#define el      	'\n'
#define ft 			first
#define sd 			second
#define mp(x,y)  	make_pair((x),(y))
#define pb(x)    	push_back((x))
#define all(v)  	((v).begin()),((v).end())
#define sz(x)  		((int) (x).size())
#define clr(a,b)	memset(a,b,sizeof(a))
typedef long long ll;
#define PI		acos(-1)
void yahia74() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin); //freopen("output.in", "w", stdout);
#endif
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
const int N = 1e2 + 2, M = 5e5 + 74, OO = 0x3f3f3f3f;

int cum[N][N];
int arr[N][N];
bool valid2(pair<int, int> i, pair<int, int> j, pair<int, int> k,
		pair<int, int> p) {
	return i.ft == j.ft && i.ft <= k.ft && i.ft <= p.ft && i.sd == k.sd
			&& i.sd <= j.sd && i.sd <= p.sd && j.ft <= k.ft && j.ft <= p.ft
			&& j.sd == p.sd && j.sd >= i.sd && j.sd >= k.sd && k.ft >= i.ft
			&& k.ft == p.ft && k.ft >= j.ft && k.sd == i.sd && k.sd <= j.sd
			&& k.sd <= p.sd && p.ft >= i.ft && p.ft >= j.ft && p.ft >= k.ft
			&& p.sd >= i.sd && p.sd >= j.sd && p.sd >= k.sd;

}
bool valid(pair<int, int> i, pair<int, int> j) {
	return i.ft <= j.ft && i.ft <= j.ft;
}
int main() {
	yahia74();
	int t, n, x, a;
	cin >> t;
	while (t--) {
		cin >> n >> x;
		for (int i = 1; i < n; ++i) {
			cin >> a;
			x ^= a;
		}
		cout << (x ? 0 : 1) << el;
	}
	return 0;
}
