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
vector<ll> res;
int n, s, a;
ll const INF = INT_MAX;

ll can(int m) {
	res.clear();
	ll i = 1;
	ll sum = 0;
	for(auto it: vec) {
		res.push_back(it + (ll)( m * i ));
		++i;
	}
	sort(res.begin(), res.end());
	for (int j = 0; j < m; ++j) {
		sum += (ll)res[j];
		if(sum > s)
			return INF;
	}
	return sum;
}

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> s;
	for (int i = 1; i <= n; ++i) {
		cin >> a;
		vec.push_back(a);
	}
	int low = 0, high = n, mid;
	while(low < high) {
		mid = low + (high-low)/2 + 1;
		if(can(mid) <= s) {
			low = mid;
		} else {
			high = mid-1;
		}
	}
	cout << low << " " << can(low);
}
