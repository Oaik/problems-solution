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
	int n, cnt = 0, mx = INT_MAX;
	string str, lett = "RGB", res = "", outp;
	cin >> n >> str;
	outp = str;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if(j == i)
				continue;
			cnt = 0, res = "";
			for (int z = 0; z < 3; ++z) {
				if(z == i || z == j)
					continue;
				for (int k = 0; k < n; ++k) {
					if(k % 3 == 0) {
						if(str[k] != lett[i]) {
							++cnt;
						}
						res += lett[i];
					}
					if(k % 3 == 1) {
						if(str[k] != lett[j]) {
							++cnt;
						}
						res += lett[j];
					}
					if(k % 3 == 2) {
						if(str[k] != lett[z]) {
							++cnt;
						}
						res += lett[z];
					}
				}
				if(cnt < mx) {
					mx = cnt;
					outp = res;
				}
			}
		}
	}
	cout << mx << "\n" << outp;
}
