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

ll arr1[100001], arr2[100001];
ll sum1[100001], sum2[100001];

int main() {
	ll v;
	int n, m, type, l, r;
	scanf("%d", &n);
	sum1[0] = 0, sum2[0] = 0;
	for (int i = 0; i < n; ++i) {
		cin >> v;
		arr1[i] = v;
		sum1[i+1] = sum1[i] + v;
	}
	sort(arr1, arr1+n);
	for (int i = 0; i < n; ++i)
		sum2[i+1] = sum2[i] + arr1[i];
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &type, &l, &r);
		if (type == 1)
			cout << sum1[r] - sum1[l-1] << "\n";
		else
			cout << sum2[r] - sum2[l-1] << "\n";
	}
}
