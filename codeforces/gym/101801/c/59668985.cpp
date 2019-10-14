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

bool valid(pair<int,int> i,pair<int,int> j){
	return i.ft <= j.ft && i.sd <= j.sd;
}
int main() {
	yahia74();
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				scanf("%d", &cum[i][j]);
				cum[i][j] += cum[i][j - 1] + cum[i - 1][j] - cum[i - 1][j - 1];
			}	
		}
		int mx = 0;
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=m;j++){
				for(int w = i;w<=n;w++){
					for(int p = j ; p <=m;p++) {
//						if(valid(mp(i,j),mp(w,p))){
							int kk = cum[w][p] - cum[i-1][p] - cum[w][j-1] + cum[i-1][j-1];
							if(kk <=k){
								int ans = (w*p)-((i-1)*p)-(w*(j-1))+((i-1)*(j-1)) ;
								mx = max(mx,ans);
							}
//						}
					}
				}
			}
		}
		printf("%d\n",mx);
//		clr(cum,0);
	}
	return 0;
}
