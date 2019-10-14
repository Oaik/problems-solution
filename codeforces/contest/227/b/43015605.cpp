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

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define ll long long

const double EPS = (1e-7);
int dcmp(double x, double y) {
	return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}

using namespace std;
vector<int> vec;
int main() {
	ll n, m, a, v = 0, p = 0;
	cin >> n;
	vec = vector<int>(n+1);
	for (ll i = 0; i < n; ++i) {
		cin >> a;
		vec[a] = i+1;
	}
	cin >> m;
	for (ll i = 0; i < m; ++i) {
		cin >> a;
		v += vec[a];
		p += n-vec[a]+1;
	}
	cout << v << " " << p;
}
