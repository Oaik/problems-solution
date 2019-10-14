#include <bits/stdc++.h>

using namespace std;

#define el      	'\n'
#define ft 			first
#define sd 			second
#define mp(x,y)  	make_pair((x),(y))
#define pb(x)    	push_back((x))
#define all(v)  	((v).begin()),((v).end())
#define sz(x)  		((int) (x).size())
#define lp(i,n) 	for(int i=0;i<(int)n;i++)
#define lpv(i,a,n) 	for(int i=a;i<=(int)n;i++)
#define clr(a,b)	memset(a,b,sizeof(a))
typedef long long ll;

void YAHIA() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
#endif
	cout << fixed << setprecision(8);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

int main() {
	int n, curr = -1, charcurr = -1;
	string inp;
	cin >> n >> inp;
	int idx = n;
	for (int i = 1; i < n; ++i) {
		if (inp[i] < inp[i-1]) {
			idx = i;
			break;
		}
	}
	for (int i = idx-1; i < n; ++i) {
		if (inp[i] - 'a' > charcurr) {
			curr = i;
			charcurr = inp[i] - 'a';
			break;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (i != curr)
			cout << inp[i];
	}
}