#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

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

using namespace std;

int main() {
	double a, x, y;
	cin >> a >> x >> y;

	if (x <= -a || x >= a)
		return cout << -1, 0;
	if( (int)y % (int)a == 0)
		return cout << -1, 0;

	if( y == a ) {
		return cout << 1, 0;
	} else if ( (int)(ceil(y/a)) % 2 == 0 || (int)(ceil(y/a)) == 1 )  {
		if (x < (a/2) && x > (-a/2)) {
			double f = (ceil(y/a));
			cout << ceil(f/2) + ( (f - (f/2) - 1) * 2 ) + 1;
		} else {
			return cout << -1, 0;
		}
	} else {
		if (x > 0 && x < a) {
			double f = (ceil(y/a));
			double b = ceil(f/2);
			cout << ceil(f/2) + ( ( f - b ) * 2 );
		} else if (x > -a && x < 0) {
			double f = (ceil(y/a));
			double b = ceil(f/2);
			cout << ceil(f/2) + ( ( f - b ) * 2 ) - 1;
		} else {
			return cout << -1, 0;
		}
	}
	return 0;
}
