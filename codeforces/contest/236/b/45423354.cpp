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

//bool valid(ll x, ll y) {
//	return x > 0 && x <= n && y > 0 && y <= n;
//}

void contest() {
	#ifndef ONLINE_JUDGE
		freopen("input.in", "r", stdin);
		freopen("output.in", "w", stdout);
	#endif
}

ll arr[10000001];

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int x, y, z;
	ll sum = 0, d, curr = 0;
	clr(arr, 0);
	cin >> x >> y >> z;
	d = x * y * z;
	for (int i = 1; i <= d; ++i) {
		for (int j = i; j <= d; j+=i) {
			arr[j]++;
		}
	}
	for (int i = 1; i <= x; ++i) {
		for (int j = 1; j <= y; ++j) {
			for (int k = 1; k <= z; ++k) {
				sum += arr[i*j*k];
			}
		}
	}
	cout << sum;
	return 0;
}
