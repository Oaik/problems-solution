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

bool arr[109];

int main() {
	int n, sum = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	for (int i = n-2; i >= 1; --i) {
		if (arr[i])
			continue;
		if (arr[i+1] == 1 && arr[i-1] == 1) {
			arr[i-1] = 0, sum++;
		}
	}
	cout << sum;
	return 0;
}