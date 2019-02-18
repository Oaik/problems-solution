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

int const mx = 35;
int n;

bool prime[mx] = {};
vector<int> primes;
void sieve() {
	prime[0] = prime[1] = 1;
	for (int i = 0; i < mx; ++i) {
		if(!prime[i]) {
			for (int j = i*i; j < mx; j += i) {
				prime[j] = 1;
			}
		}
	}
	for (int i = 2; i < mx; ++i) {
		if(!prime[i])
			primes.push_back(i);
	}
}

vector<int> chosen;
bool visited[mx] = {};
void backtracking(int len, vector<int> &chosen) {
	// base case
	if(len == n) {
		if((binary_search(primes.begin(), primes.end(),chosen[0] + chosen[chosen.size() - 1])) && (chosen.size() == n)) {
			// print
			cout << 1;
			for(int k = 1; k < n; k++)
				cout << " " <<chosen[k];
			cout << "\n";
 		}
		return;
	}

	for (int i = 2; i <= n; ++i) {
		if(!visited[i]) {
			// choose
			if( binary_search(primes.begin(), primes.end(),i + chosen[chosen.size() - 1]) ) {
				visited[i] = 1;
				chosen.push_back(i);

				// explore
				backtracking(len+1, chosen);
				// unchoose
				visited[i] = 0;
				chosen.pop_back();
			}
		}
	}

}

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	sieve();
	int i = 0;
	while(cin >> n) {
		if(i != 0)
			cout << "\n";
		chosen.clear();
		chosen.push_back(1);
		cout << "Case "<< ++i << ":\n";
		backtracking(1, chosen);
	}
}

