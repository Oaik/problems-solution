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
	vector<int> vec;
	int t, num, a, b, c;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		scanf("%d", &num);
		vec.push_back(num);
	}
	sort(vec.rbegin(), vec.rend());
	for (int i = 0; i < t-2; ++i) {
		c = vec[i], b = vec[i+1], a = vec[i+2];
		if (a + b > c) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}
