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
int arr[100000];
int main() {
	int n, m, a;
	ll v = 0, p = 0;
	scanf("%i" , &n);
	for (ll i = 0; i < n; ++i) {
		scanf("%i" , &a) ;
		arr[a] = i+1;
	}
    scanf("%i" , &m) ;
	for (ll i = 0; i < m; ++i) {
	    scanf("%i" , &a) ;
		v += arr[a];
		p += n-arr[a]+1;
	}
	printf("%I64d %I64d" , v , p) ;
}
