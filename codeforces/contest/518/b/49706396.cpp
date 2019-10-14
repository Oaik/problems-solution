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

ll const N = 2e5 + 9, M = 50009, OO = 0x3f3f3f3f;

unordered_map<char, int> mp;
bool black[N];

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	string str, text;
	cin >> str >> text;
	int n = str.length(), m = text.length(), yay = 0, ops = 0;
	for (int i = 0; i < m; ++i) {
		mp[text[i]]++;
	}
	for (int i = 0; i < n; ++i) {
		if (mp[str[i]]) {
			++yay, --mp[str[i]], black[i] = 1;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (!black[i]) {
			if ((mp[toupper(str[i])]))
				++ops, --mp[toupper(str[i])];
			else if (mp[tolower(str[i])]) {
				++ops, --mp[tolower(str[i])];
			}
		}
	}
	cout << yay << " " << ops;
	return 0;
}
