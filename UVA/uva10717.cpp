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

int arr[51];

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int n, t, cur, cnt = 0;
	while(cin >> n >> t && (n != 0 && t != 0)) {
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		for (int i = 0; i < t; ++i) {
			cin >> cur;
			for (int j = cur; j >= 0; --j) {
				cnt = 0;
				for (int k = 0; k < n; ++k) {
					if(j % arr[k] == 0) {
						++cnt;
					}
					if(cnt == 4) {
						break;
					}
				}
				if(cnt == 4) {
					cout << j << " ";
					break;
				}
			}
			for (int j = cur; 1; ++j) {
				cnt = 0;
				for (int k = 0; k < n; ++k) {
					if(j % arr[k] == 0) {
						++cnt;
					}
					if(cnt == 4) {
						break;
					}
				}
				if(cnt == 4) {
					cout << j << "\n";
					break;
				}
			}
		}
	}
}

