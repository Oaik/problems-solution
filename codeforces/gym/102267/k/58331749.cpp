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
void Yahia74() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin); //freopen("output.in", "w", stdout);
#endif
	cout << fixed << setprecision(9);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
const int N = 1e7 + 5, M = 5e5 + 74, OO = 0x3f3f3f3f;

ll arr[29];
ll n;
ll total = 0;

void DP(int x = 0, int taken = 0, ll sum = 0) {
	if(x == n) {
		if(taken > 0)
			total += sum;
		return;
	}
	DP(x+1, taken, sum);
	DP(x+1, taken + 1, sum | arr[x]);
}

int main() {
	Yahia74();
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	DP();
	cout << total;
	return 0;
}
