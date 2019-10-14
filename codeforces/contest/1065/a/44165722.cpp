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
	int t, s, b, c, a, rep;
	ll total = 0;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		total = 0;
		scanf("%d%d%d%d",&s, &a, &b, &c);
		total = s/c;
		total += (total/a) * b;
		cout << total << "\n";
	}
	return 0;
}
