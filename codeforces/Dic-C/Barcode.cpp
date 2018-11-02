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

int arr[2][1001]; // for 0-> . and 1-> x
int n, m, x, y;
int mem[1001][1001][3];

int dp(int i, int prev = 0, int num = 0) {
	if(i == m) {
		if (num < x)
			return 1000000;
		return 0;
	}

	int &ret = mem[i][num][prev];
	if (ret != -1)
		return ret;
	ret = mem[i+1][num][2];
	int hash = 1000000;
	if ( (i == 0) || (prev == 0 && num+1 <= y) || (prev == 1 && num >= x) ) {
		if (prev != 1)
			hash = dp(i+1, 0, num+1) + arr[0][i];
		else
			hash = dp(i+1, 0, 1)  + arr[0][i];
	}
	int dots = 1000000;
	if ( (i == 0) || (prev == 1 && num+1 <= y) || (prev == 0 && num >= x) ) {
		if (prev != 0)
			dots = dp(i+1, 1, num+1) + arr[1][i];
		else
			dots = dp(i+1, 1, 1)  + arr[1][i];
	}
	return ret = min(hash, dots);
}

int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	char currChar;
	cin >> n >> m >> x >> y;
	memset(arr, 0, sizeof(arr));
	memset(mem, -1, sizeof(mem));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> currChar;
			if (currChar == '.')
				++arr[0][j];
			else
				++arr[1][j];
		}
	}
	cout << dp(0, 2, 0);
}

