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

//int dx[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
//int dy[] = { 0, 0, 1, -1, -1, 1, -1, 1 };
//
//bool valid(ll x, ll y) {
//	return x > 0 && x <= n && y > 0 && y <= n;
//}

void contest() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);
#endif
}

int last[100001], diff[100001], allowed[100001];
vector<pair<int, int>> result;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, a, c, sum = 0;
	cin >> n;
	clr(diff, -1), clr(allowed, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> a;
		if (diff[a] == -2) {
			continue;
		}
		if (diff[a] == -1) {
			diff[a] = i;
			continue;
		}
		if (diff[a] && !allowed[a]) {
			allowed[a] = 1;
//			c = i - diff[a];
			last[a] = i;
			diff[a] = i - diff[a];
		} else {
			c = i - last[a];
			if (diff[a] != c) {
				diff[a] = -2;
				continue;
			}
			last[a] = i;
		}
	}
//	for (int i = 1; i <= n; ++i) {
//		if (sum[i] == 1) {
//			result.push_back({i, 0});
//		} else if (sum[i] > 1) {
//			for (int j = i; j <= n; ++j) {
//				if(number[i] != i)
//			}
//		}
//	}
	for (int i = 1; i <= 100000; ++i) {
		if (diff[i] > -1)
			++sum;
	}
	cout << sum << "\n";
	for (int i = 1; i <= 100000; ++i) {
		if (diff[i] > -1 && !allowed[i]) {
			cout << i << " 0" << "\n";
		} else if ( diff[i] > -1 && allowed[i] ) {
			cout << i << " " << diff[i] << "\n";
		}

	}
	return 0;
}

