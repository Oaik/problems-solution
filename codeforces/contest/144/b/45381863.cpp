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

//int dx[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
//int dy[] = { 0, 0, 1, -1, -1, 1, -1, 1 };
//
//bool valid(ll x, ll y) {
//	return x > 0 && x <= n && y > 0 && y <= n;
//}

void contest() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);
#endif
}

bool heated[100000];

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	vector<pair<int, pair<int, int>>> points;
	int n, x1, y1, x2, y2,minX,maxX, maxY,minY, x, y, r, q, sum = 0, index = 1;
	clr(heated, 0);
	pair<int, pair<int, int>> curr;
	cin >> x1 >> y1 >> x2 >> y2 >> q; // min , max
	minX = min(x1, x2),maxX = max(x1, x2), maxY = max(y1, y2), minY = min(y1, y2);
	for (int i = minX+1; i < maxX; ++i) {
		points.push_back({index, {i, y1}});
		points.push_back({index+1, {i, y2}});
		sum += 2, index += 2;
	}
	for (int i = maxY; i >= minY; --i) {
		points.push_back({index, {x1, i}});
		points.push_back({index+1, {x2, i}});
		sum += 2, index += 2;
	}
	int m = points.size();
	for (int i = 0; i < q; ++i) {
		cin >> x >> y >> r;
		for (int j = 0; j < m; ++j) {
			curr = points[j];
			if (heated[curr.first])
				continue;
			if ( ((curr.second.first-x)*(curr.second.first-x)) + ((curr.second.second-y)*(curr.second.second-y)) <= (r*r) ) {
				heated[curr.first] = 1;
				--sum;
			}
		}
	}
	cout << sum;
	return 0;
}
