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

int arr[100], n;
bool f = 0;
void sol(int i, int sum) {
	if(i == n) {
		if((sum % 360) == 0) {
			f = 1;
			return;
		}
		return;
	}
	sol(i+1, sum+arr[i]);
	sol(i+1, sum-arr[i]);
}

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	sol(0, 0);
	if(f == 1) cout << "YES";
	else cout << "NO";
	return 0;
}
