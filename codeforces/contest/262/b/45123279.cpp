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

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll sum = 0;
	int n, k, small, neg = 0;
	cin >> n >> k;
	cin >> arr[0];
	small = arr[0];

	for (int i = 1; i < n; ++i)
		cin >> arr[i];

	for (int i = 0; i < n; ++i) {
		if ( arr[i] < 0 && k >= 1) {
			arr[i] *= -1;
			--k;
		} else
			break;
	}

	sort(arr, arr+n);
	if (k != 0)
		arr[0] *= (k % 2 == 0) ? 1 : -1;

	for (int i = 0; i < n; ++i)
		sum += arr[i];

	cout << sum;
	return 0;
}
