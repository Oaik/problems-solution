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
//	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
const int N = 5e5 + 74, M = 5e5 + 74, OO = 0x3f3f3f3f;
map<string, double> mp;
char str[20];
int main() {
	Yahia74();
	int t ;
	scanf("%d", &t);
	double val;
	double total = 0;
	int n, m;
	while(t--){
		scanf("%d%d", &n, &m);
		total = 0;
		mp.clear();
		for (int i = 0; i < n; ++i) {
			scanf("%s", str);
			scanf("%lf", &val);
			mp[str] = val;
		}
		mp["JD"] = 1.0 ;
		bool isJD = 1;
		for (int i = 0; i < m; ++i) {
			scanf("%lf", &val);
			scanf("%s", str);
			total += (val * mp[str]);
		}
		printf("%lf\n", total);
	}
	return 0;
}
