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

bool cmp(pair<double, int> a, pair<double, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	} else {
		return a.first > b.first;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<int> vecX;
	vector<int> vecY;
	string s1;
	int n, cnt = 0;
	cin >> s1;
	n = s1.length();
	for (int i = 0; i < n; ++i) {
		if (s1[i] == '(') {
			vecX.push_back(i);
		} else {
			vecY.push_back(i);
		}
	}
	int x = vecX.size(), y = vecY.size()-1;
	for (int i = x-1; i >= 0 && y >= 0; --i) {
		if (vecX[i] < vecY[y]) {
			++cnt, --y;
		}
	}
	cout << cnt * 2;
}
