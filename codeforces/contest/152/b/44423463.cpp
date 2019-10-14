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
#define ll long long

const double EPS = (1e-7);
long long n, m;
const ll INF = 1e9;
ll bin(ll x, ll y, ll a, ll b) {
	ll end = INF;
	ll start = 0;
	ll mid;
	while(start < end) {
//		mid = ( start + end ) / 2;
		mid = ( start + (end - start) / 2 ) + 1;
		if (mid*a + x <= n && mid*a+x > 0 && mid*b + y <= m && mid*b + y > 0) {
			start = mid;
		} else {
			end = mid - 1;
		}
	}
	return start;
}

int dcmp(double x, double y) {
	return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}

int main() {
	long long x, y, k, a, b, steps = 0, q;
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < k; ++i) {
		cin >> a >> b;

//		if (a + x <= n && a+x > 0 && b + y <= m && b + y > 0) {
//			++steps;
//			x = a + x;
//			y = b + y;
//		} else {
//			break;
//		}
		q = bin(x, y, a, b);
		x = q * a + x;
		y = q * b + y;
		steps = q + steps;
	}
	cout << steps;
}
