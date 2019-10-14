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
const int N = 1e5 + 74, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

int n ;
char grid[505][505] ;
bool valid(int i ,int j ) {return i < n && j < n && i >= 0 && j >= 0 && grid[i][j] == 'X'; }
bool check(int i , int j){
	return (valid(i,j) && valid(i+1,j+1) && valid(i-1,j-1) && valid(i+1,j-1) && valid(i-1,j+1) ) ;
}

int sz[N], cost[N];
vector<pair<pair<int, int>, int>> vec;


int main() {
	Yahia74();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> sz[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> cost[i];
	}
	for (int i = 0; i < n; ++i) {
		vec.push_back({{cost[i], sz[i]}, i});
	}
	int ptr = 0;
	sort(all(vec));
	int a, b;
	ll total;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		--a;
		total = 0;
		total = min(b, sz[a]);
		b -= total;
		sz[a] -= total;
		total *= (ll)cost[a];
		if(ptr == n) {
			cout << total << '\n';
			continue;
		}
		while(b > 0) {
			int num = min(b, sz[vec[ptr].second]);
			b -= num;
			sz[vec[ptr].second] -= num;
			total += ((ll)num * (ll)cost[vec[ptr].second]);
			if(!sz[vec[ptr].second])
				++ptr;
			if(ptr == n)
				break;
		}
		if(b > 0) {
			cout << 0 << el;
			continue;
		}
		cout << total << el;
	}
}
/*




























 */
