#include <bits/stdc++.h>

using namespace std;
#define ll long long

int arr[109] = {};
set<int> st;

int main() {
    cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n, k, a, total = 0, m = 0, z = 0;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		st.insert(a);
		arr[a]++;
		z = max(z, arr[a]);
	}
	m = (z % k == 0) ? z/k : z/k + 1;
	for(auto it: st) {
		total += (k * m) - arr[it];
	}
	cout << total;
}
