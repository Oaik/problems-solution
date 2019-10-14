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
	freopen("input.in", "r", stdin);
	//freopen("output.in", "w", stdout);
#endif
//	cout << fixed << setprecision(0);
//	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
const int N = 1e6 + 9, M = 5e5 + 74, OO = 0x3f3f3f3f;
const int maxPrime = 32000;
vector<int> sieve() {
	vector<int> p;
	vector<bool> isp(maxPrime, 1);
	isp[0] = isp[1] = 0;
	for (int i = 2; i * i < maxPrime; i++)
		if (isp[i])
			for (int j = i * i; j < maxPrime; j += i)
				isp[j] = 0;
	for (int i = 0; i < maxPrime; i++)
		if (isp[i])
			p.push_back(i);
	return p;
}
vector<pair<int, int> > facto(int n, const vector<int> & primes) {
	vector<pair<int, int> > result;
	for (int i = 0; i < primes.size() && primes[i] * primes[i] <= n; i++) {
		if (n % primes[i] == 0) {
			int cnt = 0;
			while (n % primes[i] == 0) {
				n /= primes[i];
				cnt++;
			}
			result.push_back( { primes[i], cnt });
		}
	}
	if (n > 1) {
		result.push_back( { n, 1 });
	}
	return result;
}

map<int,int> mp;
vector<pair<int, int> > allFact[int(1e6 + 1)];
int main() {
	yahia74();
	vector<int> primes = sieve();
	for (int i = 1; i <= (int) 1e6 ; i++) {
		allFact[i] = (facto(i, primes));
	}
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, a;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a);
			for (int j = 0; j < (int) allFact[a].size(); ++j) {
				mp[allFact[a][j].first]++;
			}
		}
		ll steps = 0;
		for(auto it: mp){
			steps += (it.second/3) + ((it.second)%3 != 0);
		}
		cout <<  steps <<el;
		mp.clear();
	}
	return 0;
}
