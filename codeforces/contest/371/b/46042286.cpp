#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <vector>
//#include "gemo.h"

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define clr(arr, k) (memset(arr, k, sizeof(arr)))
#define lpv(i,a,n) 	for(int i=a;i<(int)n;i++)
#define ll long long

using namespace std;

const double EPS = (1e-8);
const double PI = acos(-1.0);
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

//ll x;
ll dp(ll a, ll b, ll counter = 1) {

	if (a == b) {
		return 0;
	}

	ll x = min(a, b);
	a = max(a, b);
	if (a % 5 != 0 && a % 2 != 0 && a % 3 != 0) {
		return INF;
	}

	ll cnt = INF;
	if (a % 5 == 0) {
		cnt = min(cnt, dp(x, a/5, counter) + 1);
	}
	if (a % 3 == 0) {
		cnt = min(cnt, dp(x, a/3, counter) + 1);
	}
	if (a % 2 == 0) {
		cnt = min(cnt, dp(x, a/2, counter) + 1);
	}

	return cnt;
}

using namespace std;

int main() {
	ll a, b, c;
	cin >> a >> c;
	b = min(a, c);
	a = max(a, c);
	ll gcdnum = gcd(a, b);
	a /= gcdnum, b /= gcdnum;
	ll ans = dp(a, b);
	if (ans >= INF)
		cout << -1;
	else
		cout << ans;
	return 0;
}
