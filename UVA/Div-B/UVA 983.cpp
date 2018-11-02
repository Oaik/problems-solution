#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<numeric>
#include<utility>
#include<functional>
#include<stdio.h>
#include<assert.h>
#include<memory.h>
#include<bitset>
#include <unordered_map>
using namespace std;

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define clr(arr, k) (memset(arr, k, sizeof(arr)))
#define lpv(i,a,n) 	for(int i=a;i<(int)n;i++)
#define ll long long

const double EPS = (1e-7);
const ll INF = 1e9;

int dcmp(double x, double y) {
	return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
void contest() {
	#ifndef ONLINE_JUDGE
		freopen("input.in", "r", stdin);
  		freopen("output.in", "w", stdout);
	#endif
}

ll total = 0, curr = 0;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, a, idx = 0;
	bool firstTime = true;
	contest();
	while (cin >> n >> m) {
		if (!firstTime)
			cout << "\n";
		firstTime = false;
		ll sum[n+1][n+1];
		memset(sum, 0, sizeof(sum));

		for (int i = 0; i < n; ++i) {
			for (int j = 1; j <= n; ++j) {
				cin >> a;
				sum[i][j] += sum[i][j-1] + a;
			}
		}
		idx = 0, curr = 0, total = 0;
		int x = n-m;
		for (int i = 0; i <= x; ++i) {
			idx = 0, curr = 0;
			for (int j = m; j <= n; ++j) {
//				curr += (sum[i][j] - sum[i][idx]) + (sum[i+1][j] - sum[i+1][idx] ) + ( sum[i+2][j] - sum[i+2][idx] );
//				cout << (sum[i][j] - sum[i][idx]) + (sum[i+1][j] - sum[i+1][idx] ) + ( sum[i+2][j] - sum[i+2][idx] ) << "\n";
				for (int z = 0; z < m; ++z) {
					curr += (sum[i+z][j] - sum[i+z][idx]);
				}
				cout << curr << "\n";
				total += curr;
				idx++, curr = 0;
			}
		}
		cout << total << "\n";
	}
	return 0;
}

