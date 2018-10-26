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

vector<pair<int, int>> vec;
int n, x, h;
int mem[100001][4];

int maxTree(int i, int prev) {
	// 0 -> stay, 1 -> left, 2 -> right, 3 -> init value..

	if (i == n-1) // base case
		return 0;

	int &ret = mem[i][prev]; // memorize
	if (ret != -1)
		return ret;
	ret = 0;
	ret = maxTree(i+1, 3);
	// dp
	if (vec[i].first + vec[i].second < vec[i+1].first) {
		// to the right if prev cut to left or right
		ret = max(ret, maxTree(i+1, 2) + 1);
	}
	if (prev != 2 && vec[i].first - vec[i].second > vec[i-1].first) {
		// to the left if prev was cut to left and not cut to right
		ret = max(ret, maxTree(i+1, 1) + 1);
	}
	if (prev == 2 && vec[i].first - vec[i].second > vec[i-1].first + vec[i-1].second) {
		// to the left but if prev was cut to right and not cut to left
		ret = max(ret, maxTree(i+1, 1) + 1);
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	if (n == 1) {
		cout << 1;
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		cin >> x >> h;
		vec.push_back({x, h});
	}
	memset(mem, -1, sizeof(mem));
	cout << 2 + maxTree(1, 1); // start with second tree knowing that prev tree cut to left
}

