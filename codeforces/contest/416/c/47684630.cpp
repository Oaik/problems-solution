#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<pair<pair<int, int>, int>> groups;
vector<pair<int, int>> res;
vector<pair<int, int>> ables;
bool visited[1001] = {};
// t {} []
int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	ll s = 0;
    int n, c, p, k, r, m = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
		cin >> c >> p;
        groups.push_back({{p, c}, i+1});
	}
    sort(groups.rbegin(), groups.rend());
    cin >> k;
    for (int i = 0; i < k; ++i) {
    	cin >> r;
    	ables.push_back({r, i+1});
    }
    sort(ables.begin(), ables.end());
    for (int i = 0; i < k; ++i) {
		r = ables[i].first;
		for(auto aa: groups) {
			if(!visited[aa.second] && aa.first.second <= r) {
				visited[aa.second] = 1;
				++m, s += aa.first.first;
				res.push_back({aa.second, ables[i].second});
				break;
			}
		}
	}
    cout << m << " " << s << "\n";
    for(auto ree: res) {
    	cout << ree.first << " " << ree.second << "\n";
    }
}
