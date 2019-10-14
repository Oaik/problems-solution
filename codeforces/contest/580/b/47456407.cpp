#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<pair<int, int>> vec;

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n, d, m, s;
	cin >> n >> d;
	for (int i = 0; i < n; ++i) {
		cin >> m >> s;
		vec.push_back({m, s});
	}
	sort(vec.begin(), vec.end());
	int right = 0, left = 0;
	ll sum = 0, ans = 0;
	while(left < n) {
		while(right < n && vec[right].first - vec[left].first < d) {
			sum += vec[right].second;
			++right;
		}
		ans = max(ans, sum);
		sum -= vec[left].second;
		++left;
	}
	cout << ans;
}
