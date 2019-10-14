#include <bits/stdc++.h>
#define ll    long long

using namespace std;
const int N = 1e2 + 9;

void debug() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "rt", stdin);
	#endif
}

char arr[N];

int main() {
	debug();
	int n, total = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		total += (arr[i] == '-' ? -1 : 1);
		if(total < 0)
			++total;
	}
	cout << total;
	return 0;
}
