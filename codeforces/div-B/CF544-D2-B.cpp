#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>

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
	int n, k;
	cin >> n >> k;
	if (k == 0) {
		cout << "YES\n";
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j)
				cout << "S";
			cout << "\n";
		}
		return 0;
	}
	int test = ((n*n) % 2 == 0) ? (n*n)/2 : (n*n)/2 + 1;
	if (k > test)
		return cout << "NO", 0;
	cout << "YES\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if(k && ((i % 2 == 0 && j % 2 == 0) || (i%2 == 1 && j%2 == 1) ))
				cout << "L", ++j, --k;
			if (j < n)
				cout << "S";
		}
		cout << "\n";
	}
    return 0;
}

