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
	int n, m, a;
	ll minSalary = 0, maxSalary = 0;
	scanf("%d%d", &n, &m);
	vector<int> v;
	vector<int> v1;
	for (int i = 0; i < m; ++i) {
		cin >> a;
		v.push_back(a);
		v1.push_back(a);
	}
	sort(v.begin(), v.end());
	sort(v1.begin(), v1.end());
	for (int i = 0; i < n; ++i) {
		auto it = max_element(std::begin(v), std::end(v));
		maxSalary += *it;
		--(*it);
	}
	for (int i = 0; i < n; ++i) {
		auto it = min_element(std::begin(v1), std::end(v1));
		minSalary += *it;
		--(*it);
		if (*it == 0)
			*it = 1001;
	}
	cout << maxSalary << " " << minSalary;
}


