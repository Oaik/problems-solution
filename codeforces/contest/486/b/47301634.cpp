#include <bits/stdc++.h>

using namespace std;
#define ll long long

set<pair<int,int>> st1;
set<int> stx0;
set<int> sty0;



int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int m, n, a, i = 0, j = 0;
	cin >> m >> n;
	int arr[m+1][n+1];
	memset(arr, -1, sizeof(arr));
	for (i = 0; i < m; ++i) {
		for (j = 0; j < n; ++j) {
			cin >> a;
			if(a) {
				st1.insert({i, j});
			} else {
				stx0.insert(i);
				sty0.insert(j);
			}
		}
	}
	std::set<int>::iterator it;
	for(it = stx0.begin(); it != stx0.end(); ++it) {
		for (i = 0; i < n; ++i) {
			arr[*it][i] = 0;
		}
	}
//	std::set<int>::iterator it;
	for(it = sty0.begin(); it != sty0.end(); ++it) {
		for (i = 0; i < m; ++i) {
			arr[i][*it] = 0;
		}
	}
	bool isFound = false;
	for(auto it: st1) {
		isFound = false;
		for (i = 0; i < m; ++i) {
			if(arr[i][(it.second)] == -1) {
				isFound = true;
				break;
			}
		}
		for (i = 0; i < n; ++i) {
			if(arr[it.first][i] == -1) {
				isFound = true;
				break;
			}
		}
		if(!isFound) {
			cout << "NO";
			return 0;
		}
	}
//	std::set<int>::iterator it;
	cout << "YES\n";
	for (i = 0; i < m; ++i) {
		for (j = 0; j < n; ++j) {
			cout << ((arr[i][j] == -1) ? 1: 0) << " ";
		}
		cout << "\n";
	}
}
