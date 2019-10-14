#include <bits/stdc++.h>

using namespace std;
#define ll long long

const double EPS = 1e-8;

int dcmp(double a, double b) {
	return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1;
}

vector<pair<ll, ll>> vec;

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	ll n, r, avg;
	ll a, b;
	ll total = 0, numReports = 0, req;
	cin >> n >> r >> avg;
	req = n * avg;
	for (ll i = 0; i < n; ++i) {
		cin >> a >> b;
		total += a;
		if (a < r) {
			vec.push_back({b, a});
		}
	}
	req -= total;
	if(req <= 0) {
		cout << 0;
		return 0;
	}
	sort(vec.begin(), vec.end());
	ll x;
	for(auto it: vec) {
		x = r-it.second;
		if(x < req) {
			req -= (x);
			numReports +=  it.first * (x);
		} else {
			numReports +=  it.first * (req);
			req = 0;
			break;
		}
	}
	cout << numReports;
	return 0;
}
