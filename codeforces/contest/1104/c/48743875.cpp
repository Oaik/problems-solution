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

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	string str;
	cin >> str;
	int n = str.length(), ze = 0, on = 0;
	for (int i = 0; i < n; ++i) {
		if(str[i] == '0') {
			if(ze == 0) {
				cout << 3 << " " << 4 << "\n";
				ze = 1;
			} else {
				cout << 1 << " " << 4 << "\n";
				ze = 0;
			}
		} else {
			if(on == 0) {
				cout << 1 << " " << 1 << "\n";
				on = 1;
			} else {
				cout << 1 << " " << 3 << "\n";
				on = 0;
			}
		}
	}
}
