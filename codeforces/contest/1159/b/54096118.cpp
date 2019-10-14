#include <bits/stdc++.h>
#define ll    long long

using namespace std;
const int N = 3e5 + 9;

void debug() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif
}

int arr[N];
int total = 1e9 + 9;
void solve(int firstNum, int secondNum, int diff) {
	int cur = min(firstNum, secondNum);
	cur /= (diff);
	total = min(total, cur);
}

int main() {
	debug();
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}
	for (int i = 1; i < n; ++i) {
		if(i != n)
			solve(arr[i], arr[n], n - i);
		if(i != 1)
			solve(arr[i], arr[1], i - 1);
	}
	cout << total;
	return 0;
}
