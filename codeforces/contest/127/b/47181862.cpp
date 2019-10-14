#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<int> qu;

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n, a, sm = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		qu.push_back(a);
	}
	sort(qu.begin(), qu.end());
	bool found2 = false;
	while(!qu.empty()) {
		a = qu.back();
		qu.pop_back();
		while(a != qu.back() && !qu.empty()) {
			a = qu.back();
			qu.pop_back();
		}
		if(qu.empty()) break;
		qu.pop_back();
		if(qu.empty()) break;
		a = qu.back();
		qu.pop_back();
		while(a != qu.back() && !qu.empty()) {
			a = qu.back();
			qu.pop_back();
		}
		if(a == qu.back() && !qu.empty())
			++sm;
		if(!qu.empty())
			qu.pop_back();
	}
	cout << sm;
}
