#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define all(v)  	((v).begin()),((v).end())
#define sz(x)  		((ll) (x).size())
#define clr(a,b)	memset(a,b,sizeof(a))
const double EPS = 1e-8;
const double pi = acos(-1);
ll dcmp(double a, double b) {
	return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1;
}
void debug() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "rt", stdin);
//	freopen("output.in", "wt", stdout);
#endif
}

int const N = 1e6 + 9, M = 100 + 9, OO = 1e9;

int arr[509][509];

bool isPrime[N];
vector<int> primes;

void sieve() {
	int max = 1e6+7;
	isPrime[0] = isPrime[1] = 1;
	for (int i = 2; i * i < max; ++i) {
		if(!isPrime[i]) {
			for (ll j = (ll)i * i; j < max; j += i) {
				isPrime[j] = 1;
			}
		}
	}
	for (int i = 2; i < max; ++i) {
		if(!isPrime[i])
			primes.push_back(i);
	}
}

int main() {
	cout << fixed << setprecision(6);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	sieve();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
		}
	}
	ll mnNum = 1e9, cnt = 0;
	for (int i = 0; i < n; ++i) {
		cnt = 0;
		for (int j = 0; j < m; ++j) {
			if(!isPrime[arr[i][j]])
				continue;
			auto up = upper_bound (primes.begin(), primes.end(), arr[i][j]);
			cnt += primes[up-primes.begin()] - arr[i][j];
		}
		mnNum = min(cnt, mnNum);
	}
	for (int j = 0; j < m; ++j) {
		cnt = 0;
		for (int i = 0; i < n; ++i) {
			if(!isPrime[arr[i][j]])
				continue;
			auto up = upper_bound (primes.begin(), primes.end(), arr[i][j]);
			cnt += primes[up-primes.begin()] - arr[i][j];
		}
		mnNum = min(cnt, mnNum);
	}

	cout << mnNum;
}
