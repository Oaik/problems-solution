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

int arr[100000];
int sum[100001] = {0};

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, q, i, j;
	while(cin >> n && n) {
		sum[0] = 0;
		for (int x = 0; x < n; ++x) {
			cin >> arr[x];
			sum[x+1] = sum[x] + arr[x];
		}
		cin >> q;
		for (int x = 0; x < q; ++x) {
			cin >> i >> j;
			cout << sum[j+1] - sum[i] << "\n";
		}
	}
	return 0;
}

