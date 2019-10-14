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

bool visited[1001] = {};
int arr[1001];
int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n,i, x = 0, total = 0;
	cin >> n;
	for (i = 0; i < n; ++i) {
		cin >> x;
		arr[i] = x;
	}
	sort(arr, arr+n);
	int m = n-1;
	for (i = 0; i < m; ++i) {
		for (int j = i+1; j < n; ++j) {
			if(!visited[j] && arr[j] > arr[i]) {
				visited[j] = 1, ++total;
				break;
			}
		}
	}
	cout << total;
}
