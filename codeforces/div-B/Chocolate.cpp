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

bool arr[101];

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	ll n, nuts = 0, prev = -1, sum = 0, total = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		nuts += arr[i];
	}
	if (nuts == 0) {
		cout << 0;
		return 0;
	}
	if (nuts == n || nuts == 1) {
		cout << 1;
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		if (arr[i] == 1) {
			if (prev == -1) {
				total = 1;
			} else {
				total *= i - prev;
			}
			prev = i;
		}
	}
	cout << total;
	return 0;
}

