#include <bits/stdc++.h>

using namespace std;
#define ll long long

map<char, int> contain;
map<char, int> should;

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	string a, b;
	int cnt = 0;
	cin >> a >> b;
	int n1 = a.length(), n2 = b.length();
	for (int i = 0; i < n1; ++i) {
		contain[a[i]]++;
	}
	for (int i = 0; i < n2; ++i) {
		should[b[i]]++;
	}
	for(auto it: should) {
		if(contain[it.first] == 0) {
			cout << -1;
			return 0;
		}
		cnt += min(it.second, contain[it.first]);
	}
	cout << cnt;
}
