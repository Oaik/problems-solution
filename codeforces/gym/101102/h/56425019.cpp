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
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
const int N = 5e5 + 74, M = 5e5 + 74, OO = 0x3f3f3f3f;


int main() {
	Yahia74();
	int t;
	cin >> t;
	while(t--) {
		ll c,k;
		string seats;
		cin>>c>>k>>seats;
		++k;
		ll con=0;
		bool can = 0;
		for (ll i=0;i<c && !can;i++)
		{
			if(seats[i]=='0')
			{
				con++;
				if (con>=k)
				{
					can = 1;
					break;
				}
			}
			else
			{
				con=0;
			}
		}
		if (!can)
			cout<<"no"<<'\n';
		else
			cout<<"yes"<<'\n';

	}
	return 0;
}


