#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <iomanip>

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
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}


int main() {
	ll t, a, b, k;
	ll total;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		total = 0;
		cin >> a >> b >> k;
		if (k % 2 == 0) {
			total = (a*(k/2)) - (b * (k/2));
		} else {
			total = (a*((k+1)/2)) - (b * ((k)/2));
		}
		cout << total << "\n";
	}
	return 0;
}