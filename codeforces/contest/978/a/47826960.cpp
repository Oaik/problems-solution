#include <bits/stdc++.h>

using namespace std;
#define ll long long

const double EPS = 1e-8;

int dcmp(double a, double b) {
	return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1;
}

bool visited[1001] = {};
int arr[1001];
int store[1001];

int main() {
//	freopen("input.in", "r", stdin);
//	freopen("output.in", "w", stdout);
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n, len, cnt = 0;
	string str;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> store[i];
	}
	reverse(store, store + n);
	for (int i = 0; i < n; ++i) {
		if(visited[store[i]] == 0) {
			visited[store[i]] = 1;
			arr[cnt] = store[i];
			++cnt;
		}
	}
	cout << cnt << "\n";
	for (int i = cnt-1; i >= 0; --i) {
		cout << arr[i] << " ";
	}
	return 0;
}
