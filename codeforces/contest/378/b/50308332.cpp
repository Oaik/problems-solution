#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define all(v)  	((v).begin()),((v).end())
#define sz(x)  		((ll) (x).size())
#define clr(a,b)	memset(a,b,sizeof(a))
const double EPS = 1e-8;
const double pi = acos(-1);
ll dcmp(double a, double b) {
	return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1;
}
void debug() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "rt", stdin);
	//freopen("output.in", "wt", stdout);
#endif
}

int const N = 1e5 + 9, M = 100 + 9, OO = 5e8 + 9;

int arr1[N], arr2[N];
vector<pair<bool, int>> vec;
int str1[N], str2[N];

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr1[i] >> arr2[i];
		str1[i] = 0, str2[i] = 0;
	}
	int m = n/2;
	for (int i = 0; i < m; ++i) {
		str1[i] = str2[i] = 1;
	}
	int ptr1 = 0, ptr2 = 0, cnt = 0;
//	m = n-2;
	while(cnt < n) {
		if(arr1[ptr1] < arr2[ptr2] && ptr1 < n) {
			vec.push_back({0, ptr1});
			++ptr1;
		} else {
			vec.push_back({1, ptr2});
			++ptr2;
		}
		++cnt;
	}
	for(auto it: vec) {
		if(it.first) {
			str2[it.second] = 1;
		} else
			str1[it.second] = 1;
	}
	for (int i = 0; i < n; ++i) {
		cout << str1[i];
	}
	cout << "\n";
	for (int i = 0; i < n; ++i) {
		cout << str2[i];
	}
	return 0;
}
