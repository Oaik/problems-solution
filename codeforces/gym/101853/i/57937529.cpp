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
	cout << fixed << setprecision(6);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
const int N = 1e6 + 5, M = 5e5 + 74, OO = 0x3f3f3f3f;


int main() {
	Yahia74();
	int t;
	cin>>t;
	while(t--) {
		ll a,b,d;
		cin>>a>>b>>d;
		double ArSq,ArCir,ArSem,ArXs,req;
		ArSq = 0.5*(d*d);
		ArCir = PI * (d/2.0) *(d/2.0);
		ArSem = (sqrt(ArSq)/2.0)*(sqrt(ArSq)/2.0)*PI*2;
		ArXs = ArCir - ArSq;
		req = ArSem - ArXs;
		cout<<req<<el;

	}
	return 0;
}
