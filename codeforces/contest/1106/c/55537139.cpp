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
	freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
const int N = 3e5 + 74, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

int a[N] ;
int main() {
	Yahia74();
	int n ;
	cin >> n ;
	for (int i = 0; i < n; ++i) {
		cin >> a[i] ;
	}
	sort(a,a+n) ;
	ll mn = 0 ;
	for(int i = 0 ; i < n /2 ; i++){
		mn += (ll)((ll)a[i]+a[n-i-1])*((ll)a[i]+a[n-i-1]) ;
	}
	cout << mn << el;
}
/*




























 */
