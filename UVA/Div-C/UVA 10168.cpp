#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define all(v)  	((v).begin()),((v).end())
#define sz(x)  		((int) (x).size())
#define clr(a,b)	memset(a,b,sizeof(a))
const double EPS = 1e-8;
const double pi = acos(-1);

int dcmp(double a, double b) {
	return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1;
}
void debug() {
	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);
}

const int mx = 10000000;
bool primes[mx+1] = {};
vector<int> pr;

void sieve() {
	primes[0] = primes[1] = 1;
	for (ll i = 2; i * i < mx; ++i) {
		if(!primes[i]) {
			for (ll j = i*i; j < mx; j += i) {
				primes[j] = 1;
			}
		}
	}
	for (int i = 0; i < mx; ++i) {
		if(!primes[i])
			pr.push_back(i);
	}
}

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	sieve();
	int n;
	bool found = false;
	while(cin >> n) {
		found = false;
		if(n < 8) {
			cout << "Impossible.\n";
			continue;
		}
		int i = 0, j = 0, k = 0;
		for (i = 0; i < 50 && pr[i] < n && !found; ++i) {
			for (j = 0; j < 50 && pr[i] + pr[j] < n && !found; ++j) {
				for (k = 0; k < 50 && pr[j] + pr[i] + pr[k] < n && !found; ++k) {
					if(binary_search(pr.begin(), pr.end(), (n - (pr[i] + pr[j] + pr[k])) )) {
						found = true;
						cout << pr[i] << " " << pr[j] << " " << pr[k] << " " << (n - (pr[i] + pr[j] + pr[k])) << "\n";
					}
				}
			}
		}
		if(!found)
			cout << "Impossible.\n";
	}
}

