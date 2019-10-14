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
void Yahia74() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin); //freopen("output.in", "w", stdout);
#endif
	cout << fixed << setprecision(6);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
const int N = 1e4 + 5, M = 5e5 + 74, OO = 0x3f3f3f3f;

int f[N];
int main() {
	Yahia74();
	int t;
	cin >> t;
	while (t--) {
		int n  ;
		cin >> n ;
		clr(f,0) ;
		for(int i = 0 ; i < n ; i++){
			int x ;
			cin >> x ;
			f[x]++ ;
		}
		int  mx = 0;
		for(int i = 1 ; i <= 10000 ;i++){
			mx = max(mx,f[i] + f[i-1]) ;
		}
		cout << mx << el ;
	}
	return 0;
}
