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

int arr[1009];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}
	arr[0] = 1009;
	int val = min(arr[1], arr[n]);
	for (int i = n-1; i >= 1; --i) {
		if (arr[i] > arr[i-1]) {
			val = min(val, arr[i]);
		} else {
			val = min(val, arr[i-1]);
			--i;
		}
	}
	cout << val;
	return 0;
}
