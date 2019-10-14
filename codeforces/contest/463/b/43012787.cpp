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
	vector<int> vec;
	int n, a = 0, total = 0, energy = 0;
	cin >> n;
	vec = vector<int>(n);
	for (int i = 0; i < n; ++i) {
		cin >> vec[i];
	}
	auto it = max_element(std::begin(vec), std::end(vec));
	a = total = *it;
	for (int i = 0; i < n; ++i) {
		if (a - vec[i] + energy < 0) {
			while(a-vec[i]+energy < 0) {
				++total;
				++a;
			}
			energy += a-vec[i];
		} else {
			energy += a-vec[i];
		}
		a = vec[i];
	}
	cout << total;
	return 0;
}
