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
bool valid(char c) {
	return c == 'A' || c == 'H' || c == 'I' || c == 'M' || c == 'O' || c == 'T'
			|| c == 'U' || c == 'V' || c == 'W' || c == 'X' || c == 'Y';
}
int mem[N][N];
string s;
int solve(int i, int j) {
	if (i > j)
		return 0;
	if (i == j) {
		if (valid(s[i]))
			return 1;
		else
			return -OO;
	}
	int &ret = mem[i][j];
	if (~ret)
		return ret;
	ret = 0;
	int ch1 = 0, ch2 = 0, ch3 = 0;
//	ret = solve(i+1, j-1);
	if (s[i] == s[j] && valid(s[i]))
		ch3 = solve(i + 1, j - 1) + 2;
	ch1 = solve(i + 1, j);
	ch2 = solve(i, j - 1);
	ret = max(max(ch3, ch1), ch2);
	return ret;
}

int a[100005] ;
int main() {
	Yahia74();
	int t;
	cin >> t;
	while (t--) {
//		cin >> s ;
//		clr(mem,-1) ;
//		cout << solve(0,sz(s)-1)  << el;
//		int a, b, n;
//		cin >> a >> b >> n;
//		int freq[10];
//		clr(freq, 0);
//		int x = 1;
//		while (((a * x * x) + (b * x)) <= n) {
//			int num = (a * x * x) + (b * x);
//			while (num > 0) {
//				freq[num % 10]++;
//				num /= 10;
//			}
//			x++;
//		}
//		if (a + b > n)
//			cout << -1 << el;
//		else {
//			int cnt = 0
//			for(int i=0;i<10;i++)
//				cnt = max(cnt,)
//
//		}
		int n ;
		cin >> n ;
		for(int i = 0 ;i < n ;i++)
			cin >> a[i] ;
		sort(a,a+n) ;
		bool ok = true ;
		for(int i = 0 ;i < n-1 ;i++){
			if((a[i+1] - a[i])&1){
				ok = false ;
				break ;
			}
		}
		if(ok)
			cout << "yes\n" ;
		else
			cout << "no\n" ;
	}

	return 0;
}
