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

int const N = 1e5 + 9, M = 100 + 9, OO = 1e9;

int arr[N];
vector<pair<int, int>> vec;

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	bool found = true;
	int smallest = 1e9, largest = 0, sIndx = 0, lIndx = 0, ans = 1e9, cnt = 0;
	for (int i = 0; i < k; ++i) {
		smallest = 1e9, largest = 0;
		for (int j = 0; j < n; ++j) {
			if (arr[j] > largest) {
				largest = arr[j], lIndx = j;
			}
			if (arr[j] < smallest) {
				smallest = arr[j], sIndx = j;
			}
		}
		if(lIndx == sIndx) {
			break;
		}
		++arr[sIndx], --arr[lIndx];
//		--largest, ++smallest;
		++cnt;
		ans = min(ans, largest - smallest);
		vec.push_back( { lIndx + 1, sIndx + 1 });
	}
	smallest = 1e9, largest = 0;

	for (int j = 0; j < n; ++j) {
		if (arr[j] > largest) {
			largest = arr[j], lIndx = j;
		}
		if (arr[j] < smallest) {
			smallest = arr[j], sIndx = j;
		}
	}
	cout << largest - smallest << " " << cnt << "\n";
	for (auto it : vec) {
		cout << it.first << " " << it.second << "\n";
	}
	return 0;
}
