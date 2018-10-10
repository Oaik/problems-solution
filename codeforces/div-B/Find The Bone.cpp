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

bool holes[1000000];

int main() {
	int n, m, k, a, b, curr = 1;
	scanf("%d%d%d", &n, &m, &k);
	memset(holes, 0, sizeof(holes));
	for (int i = 0; i < m; ++i) {
		scanf("%d", &a);
		holes[a] = 1;
	}
	if(holes[1]) {
		printf("%d", 1);
		return 0;
	}
	for (int i = 0; i < k; ++i) {
		scanf("%d%d", &a, &b);
		if (a == curr) {
			curr = b;
		} else if (b == curr) {
			curr = a;
		}
		if (holes[curr]) {
			printf("%d", curr);
			return 0;
		}
	}
	printf("%d", curr);
	return 0;
}

