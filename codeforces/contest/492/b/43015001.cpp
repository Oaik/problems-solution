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
double arr[1000];
int main() {
	double a = 0.0, max = 0.0;
	int n, l;
	cin >> n >> l;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	sort(arr, arr + n);
	if ((arr[0] - a) > max)
		max = (arr[0]);
	a = arr[0];
	for (int i = 1; i < n; ++i) {
		if ((arr[i] - a) / 2 > max)
			max = (arr[i] - a) / 2;
		a = arr[i];
	}
	if ((l - arr[n - 1]) > max)
		max = (l - arr[n - 1]);
	cout << fixed << setprecision(10) << max;
}
