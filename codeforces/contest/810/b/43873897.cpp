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

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define ll long long

const double EPS = (1e-7);
int dcmp(double x, double y) {
	return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}

using namespace std;

int main() {
	int n, f, k, l;
	ll total = 0;
	scanf("%i%i", &n, &f);
	vector<pair<ll, pair<ll, ll>>> elm;
	for (int i = 0; i < n; ++i) {
		scanf("%i%i", &k, &l);
		elm.push_back({min(k, l-k),make_pair(l, k)});
	}
	sort(elm.rbegin(), elm.rend());
	for (int i = 0; i < f; ++i)
		elm[i].second.second *= 2;
	for (int i = 0; i < n; ++i)
		total += min(elm[i].second.first, elm[i].second.second);
	cout << total;
}
