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

int dcmp(double x, double y) {
	return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}

bool cmp(pair<double, int> a, pair<double, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	} else {
		return a.first > b.first;
	}
}

int main() {
	vector<pair<double, int>> vec;
	double n, t1, t2, k, a, b;
	double result;
	cin >> n >> t1 >> t2 >> k;
//	scanf("%d%d%d%d", &n, &t1, &t2, &k);
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		result = max( (a - (k/100 * a)) * t1 + b * t2, (b - (k/100 * b) ) * t1 + a * t2);
		vec.push_back({result, i + 1});
	}
	sort(vec.begin(), vec.end(), cmp);
	for (int i = 0; i < n; ++i) {
		pair<double, int> it = vec[i];
//		pq.pop();
		cout << setprecision(2) << fixed << it.second << " " << it.first << "\n";
	}
}
