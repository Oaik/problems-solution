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

int main() {
	Yahia74();
	cin >> n ;
	for (int i = 0; i < n; ++i) {
		cin >> grid[i] ;
	}
	int cnt = 0 ;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if(check(i,j))
				++cnt ;
		}
	}
	cout << cnt ;
	return 0;
}
/*




























 */
