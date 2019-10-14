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
const int N = 1e3 + 5, M = 5e5 + 74, OO = 0x3f3f3f3f;
ll freq[10], ff[10];
int main() {
	Yahia74();
	int t;
	cin >> t;
	while (t--) {
		ll a, b, n;

		cin >> a >> b >> n;
		clr(freq, 0);
		ll x = 1;
		while (((a * x * x) + (b * x)) <= n) {
			ll num = (a * x * x) + (b * x);
//			cout<<num<<el;
			clr(ff, 0);
			while (num > 0) {
				ff[num % 10]++;
				num /= 10;
			}

			ll mxx = 0;
			for(int i=0;i<10;i++)
				mxx = max(mxx,ff[i]);

			for (int i = 0; i < 10; ++i) {
				if(ff[i] == mxx)
					++freq[i];
			}
			x++;
		}
		//cout<<"lol\n";
		if (x<2)
			cout << -1 << el;
		else {
			ll cnt = 0,lol=-1;
			for(int i=0;i<10;i++)
				cnt = max(cnt,freq[i]);
			for(int i=0;i<10;i++)
			{
				if (freq[i]==cnt)
				{
					lol = i;
					break;
				}
			}
			cout<<lol<<el;
		}
	}
	return 0;
}
