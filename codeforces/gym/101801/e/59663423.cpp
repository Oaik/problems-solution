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
	freopen("input.in", "r", stdin);
	//freopen("output.in", "w", stdout);
#endif
//	cout << fixed << setprecision(0);
//	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
const int N = 1e6 + 9, M = 5e5 + 74, OO = 0x3f3f3f3f, MOD = 1e9 + 7;

int mem[109][109][128];

int solve(int idx,int left, int sofar) {
	if(left < 0)
		return 0;
	if(left == 0) {
		if(sofar != 0)
			return 1;
		return 0;
	}
	int& ret = mem[idx][left][sofar];
	if(~ret)
		return ret;
	ret = 0;
	for (int i = 1; i <= left; ++i) {
		ret = (ret % MOD + solve(idx,left - i, sofar ^ (i)) % MOD) % MOD;
	}
	return ret;
}

int main() {
	yahia74();
	int t;
	scanf("%d", &t);
	clr(mem, -1);
	for (int i = 1; i <= 100; ++i) {
		solve(i, i, 0);
	}
	int n;
	while(t--) {
		scanf("%d", &n);
		printf("%d\n", mem[n][n][0]);
	}
	return 0;
}
