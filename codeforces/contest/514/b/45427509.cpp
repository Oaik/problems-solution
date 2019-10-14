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
	double n, rx, ry, x, y;
	double d;
	set<double> points;
	ll total = 0;
	bool foundX = false, foundY = false;
	cin >> n >> rx >> ry;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		if (x == rx) {
			if(!foundX)
				foundX = true, total++;
		} else if (y == ry) {
			if(!foundY)
				foundY = true, total++;
		} else {
			d = (x-rx) / (y-ry);
			points.insert(d);
		}
	}
	cout << total + points.size();
	return 0;
}
