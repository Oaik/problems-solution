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
#define clr(arr, k) (memset(arr, k, sizeof(arr)))
#define lpv(i,a,n) 	for(int i=a;i<(int)n;i++)
#define ll long long

const double EPS = (1e-7);
const ll INF = 1e9;

int dcmp(double x, double y) {
	return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void contest() {
	freopen("input.in", "r", stdin);
}

int a[101], mem[101][3] ,  n;
int minDay(int i, int pre = 0) {
	if (i > n  )
		return 0;
	int &ret = mem[i][pre];
	if (ret != -1)
		return ret;
	ret = minDay(i + 1, 0) + 1;
	if (a[i] == 1 && pre != 1)
		ret = min(ret, minDay(i + 1, 1));
	else if (a[i] == 2 && pre != 2)
		ret = min(ret, minDay(i + 1, 2));
	else if (a[i] == 3)
		if (pre == 0)
			ret = min(ret, min(minDay(i + 1, 1), minDay(i + 1, 2)));
		else
			ret = min(ret, minDay(i + 1, (pre == 1 ? 2 : 1)));
	return ret;
}

int main() {
	cin >> n; lpv(i,1,n+1) cin >> a[i];
	clr(mem,-1) ;
	cout << minDay(1);
	return 0;
}
