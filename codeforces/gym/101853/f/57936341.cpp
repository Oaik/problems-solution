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
const int N = 1e6 + 5, M = 5e5 + 74, OO = 0x3f3f3f3f;

unordered_map<int, int> mp;
int arr[N];

int main() {
	Yahia74();
	int t, n, m;
	cin>>t;
	while(t--) {
		int n,m,work=0;
		cin>>n>>m;
		m *=60;
		for (int i = 0; i < n; ++i) {
			int hs,ms,he,me;
			string start,end;
			cin>>start>>end;
			hs = (start[0]-'0')*10+(start[1]-'0');
			ms = (start[3]-'0')*10+(start[4]-'0');
			he = (end[0]-'0')*10+(end[1]-'0');
			me = (end[3]-'0')*10+(end[4]-'0');
			if(me<ms)
				me+=60,he--;
			work += me-ms;
			work += (he-hs)*60;
		}
//		int minutesover = works%60;
//		works -= minutesover;
//		work = works/60 + workh;
//		work += minutesover/60.0;
//		//cout<<work<<el;
		if(work>=m)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}
