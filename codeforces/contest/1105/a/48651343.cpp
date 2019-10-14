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

int arr[1001];
set<int> st;

int main() {

	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n, mx = INT_MAX, cur = 0, mni = INT_MAX,mxi = 0, fimni, fimxi;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		st.insert(arr[i]);
	}
	for(auto itt: st) {
		for (int it = ((itt-1) > 0 ? itt-1: 1); it < itt+2; ++it) {
			cur = 0, mni = INT_MAX,mxi = 0;
			for (int i = 0; i < n; ++i) {
				if(arr[i] > it) {
					cur += arr[i] - (it + 1);
					mxi = max(mxi, (it + 1));
				} else if (arr[i] < it) {
					cur += (it-1) - arr[i];
					mni = min(mni, (it-1));
				}
			}
			if(cur < mx) {
				mx = cur;
				fimni = mni, fimxi = mxi;
				if(fimni == INT_MAX) {
					fimni = it-1;
				}
				if(fimxi == 0)
					fimxi = it+1;
			}
		}
	}
	cout << (fimni + fimxi)/2 << " " << mx;
}
