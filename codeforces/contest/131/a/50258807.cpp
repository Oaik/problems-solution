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

int const N = 50 + 9, M = 100 + 9, OO = 5e8 + 9;
unsigned long long
choose(unsigned long long n, unsigned long long k) {
    if (k > n) {
        return 0;
    }
    unsigned long long r = 1;
    for (unsigned long long d = 1; d <= k; ++d) {
        r *= n--;
        r /= d;
    }
    return r;
}

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	string str;
	cin >> str;
	bool can = true;
	int n = str.size();
	for (int i = 1; i < n; ++i) {
		if(islower(str[i])) {
			can = false;
			break;
		}
	}
	if(!can) {
		cout << str;
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		if(islower(str[i])) {
			cout << (char)toupper(str[i]);
		} else {
			cout << (char)tolower(str[i]);
		}
	}
	return 0;
}
