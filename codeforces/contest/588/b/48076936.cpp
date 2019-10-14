#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define all(v)  	((v).begin()),((v).end())
#define sz(x)  		((int) (x).size())
#define clr(a,b)	memset(a,b,sizeof(a))
const double EPS = 1e-8;

int dcmp(double a, double b) {
	return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1;
}
void debug() {
	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);
}

vector<ll> vec;
void getDivsors(ll n) {
	for (ll i = 1; i * i <= n; ++i) {
		if(n % i == 0)
			vec.push_back(i),vec.push_back(n/i);
	}
	sort(vec.begin(), vec.end(), std::greater<ll>());
}

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	ll n, num;
	bool found = true;
	cin >> n;
	getDivsors(n);
	for(auto it: vec) {
		found = true, num = it;
		for (ll i = 2; i * i <= it && found; ++i) {
			if(it % (i*i) == 0)
				found = false;
		}
		if(found)
			break;
	}
	cout << num;
}
