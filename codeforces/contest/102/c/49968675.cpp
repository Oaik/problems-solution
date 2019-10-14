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

int const N = 1e5 + 9, M = 500, OO = 5e8 + 9;

pair<int, char> letters[26];

bool cmp(pair<int, char> a, pair<int, char> b) {
	return a.second < b.second;
}

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	string s;
	int n;
	cin >> s >> n;
	int m = s.size();
	if (n >= m) {
		cout << 0 << "\n";
		cout << "\n";
		return 0;
	}
	for (int i = 0; i < 26; ++i) {
		letters[i] = {0, (char)('a' + i)};
	}
	for (int i = 0; i < m; ++i) {
		letters[s[i] - 'a'] = {letters[s[i] - 'a'].first + 1, s[i]};
	}
	sort(letters, letters + 26);
	int idx = 0, tmp;
	while (n > 0 && idx < 26) {
		if (n >= letters[idx].first) {
			n -= letters[idx].first;
			letters[idx].first = 0;
		} else {
			letters[idx].first -= n;
			n = 0;
		}
		++idx;
	}
	int d = 0;
	for (int i = 0; i < 26; ++i) {
		if (letters[i].first)
			++d;
	}
	cout << d << "\n";
	sort(letters, letters+26, cmp);
	for (int i = 0; i < m; ++i) {
		char lt = s[i];
		if(letters[lt-'a'].first) {
			--letters[lt-'a'].first;
			cout << lt;
		}
	}
//	for (int i = 0; i < 26; ++i) {
//		if (letters[i].first) {
//			lp = letters[i].first;
//			for (int j = 0; j < lp; ++j) {
//				cout << letters[i].second;
//			}
//		}
//	}
	return 0;
}
