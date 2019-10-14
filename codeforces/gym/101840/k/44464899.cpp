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

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("katryoshka.in", "r", stdin);
	int t, n, m, k, minNum, cases = 0;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cases = 0, minNum = 0;
		cin >> n >> m >> k;
		if (m != 0) {
			minNum = min(min(n, m), k);
			n -= minNum, m -= minNum, k -= minNum, cases += minNum;
		}
		if (m == 0) {
			minNum = min(n/2, k);
			n -= minNum * 2, k -= minNum, cases += minNum;
		}
		cout << "Case " << i + 1 << ": " << cases << "\n";
	}
}
