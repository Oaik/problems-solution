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

bool arr[101];

int main() {
	int t, n, counter;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		counter = 0;
		memset(arr, 0, sizeof(arr));
		scanf("%d", &n);
		for (int k = 1; k <= n; ++k) {
			for (int j = k+1; j <= n; j += k + 1)
				arr[j] = !arr[j];
		}
		for (int k = 1; k <= n; ++k) {
			if (!arr[k])
				++counter;
		}
		printf("%d\n", counter);
	}
}

