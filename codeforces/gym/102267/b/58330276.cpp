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
const int N = 1e7 + 5, M = 5e5 + 74, OO = 0x3f3f3f3f;

bool isPrime[N] ;
vector<int> primes ;
void seive(int n = N){
	clr(isPrime,true) ;
	for(int i = 2 ; i < N ;i++){
		if(isPrime[i]){
			primes.pb(i);
			for(int j = i + i ; j < N ;j+=i){
				isPrime[j] = false ;
			}
		}
	}
}
int main() {
	Yahia74();
	seive() ;
	int n ;
	cin >> n ;
	for(int i = 0 ; i < sz(primes);i++){
		if(binary_search(all(primes),n-primes[i])){
			return cout << primes[i] << ' ' << n-primes[i] << el , 0 ;
		}
	}
	cout << -1 << el ;
	return 0;
}
