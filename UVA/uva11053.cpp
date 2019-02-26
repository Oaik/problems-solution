#include <bits/stdc++.h>

using namespace std;
#define ll long long
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
	//freopen("output.in", "wt", stdout);
#endif
}

int const N = 1e9 + 9, M = 100 + 9, OO = 1e9;

unordered_map<int, short int> mp;

vector<int> vec;

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	unsigned long long n, a, b, cnt, j, idx = 0, elm, hi = 0;
	short int mxVal = 0;
	bool can = true;
	while (cin >> n, n) {
		mxVal = 0, elm = 0, j = 0, cnt = 0, idx = 0, can = 1, hi = 0;
		cin >> a >> b;
		mp.clear();
		vec.clear();
		while (idx < n) {
			++mp[j];

			if (mp[j] == 1)
				++elm;
			if (mp[j] == 2)
				++cnt;

			if(can)
				vec.push_back(j);

			if (mp[j] > mxVal) {
				mxVal = mp[j];
				if (mxVal == 3)
					break;
				else if (mxVal == 2) {
					can = 0;
					hi = idx;
				}
			}

			j = (((a % n) * (((j * j)) % n)) % n + (b % n)) % n;
			++idx;
		}
		// case 0, 1, 2
		if (mxVal == 2) {
			for (int i = hi-1; i >= 0; --i) {
				if(mp[vec[i]] == 1)
					++cnt;
			}
			cout << n - cnt << endl;
		} else if (mxVal == 1)
			cout << 0 << endl;
		else
			cout << n - cnt << endl;
	}
	return 0;
}

