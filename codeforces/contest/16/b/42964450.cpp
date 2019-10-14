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

int main() {
	multimap<int, int, std::greater<int> > mymap;
	int sum = 0, n, m, a, b;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		mymap.emplace(b, a);
	}
	for (multimap<int, int>::iterator it = mymap.begin(); it != mymap.end() && n > 0;
			++it) {
		if (n - it->second > 0) {
			sum += it->second * it->first;
		} else {
			sum += n * it->first;
		}
		n-= it->second;
	}

	cout << sum;
	return 0;
}
