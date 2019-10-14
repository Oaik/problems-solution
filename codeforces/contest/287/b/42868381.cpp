#include <iostream>
#include <vector>

#define sz(v) (int)v.size()
#define ll long long

using namespace std;

// sum: 1 2 3 ... n
ll sum(ll n) {
	return (n * (n + 1)) / 2;
}

// sum: s s+1 s+2 ... e
ll sum(ll s, ll e) {
	if (s <= 1)
		return sum(e);

	return sum(e) - sum(s - 1);
}

ll minSplitters(ll k, ll n) {
	ll st = 1, en = k;

	while (st < en) {
		ll md = (st + en) / 2;
		ll s = sum(md, k);

		if (s == n)
			return k - md + 1;

		if (s > n)
			st = md + 1;
		else
			en = md;
	}

	return k - st + 2;
}

int main() {
	ll n, k;
	cin >> n >> k;

	if (n == 1)
		cout << 0 << "\n";      // already just 1 out flow source exist
	else if (n <= k)
		cout << 1 << "\n";      // we have 1-n splitter already
	else {
		--k;
		--n;

		if (sum(k) < n)
			cout << -1 << "\n";
		else
			cout << minSplitters(k, n) << "\n";
	}

	return 0;
}
