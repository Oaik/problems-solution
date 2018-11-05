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
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);
#endif
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	contest();
	string str;
	cin >> str;
	int n = str.length();
	queue<pair<int, int>> que;
	char a, b, c, d;
	a = str[0], b = str[1], c = str[2];
	for (int i = 3; i < n; ++i) {
		a = str[i - 3], b = str[i - 2], c = str[i - 1], d = str[i];
		if (a == 'b' && b == 'e' && c == 'a' && d == 'r') {
			que.push({i, n-i});
		}
	}
	if (que.empty()) {
		cout << 0;
		return 0;
	}
	bool more = false;
	ll sum = 0;
	pair<int, int> prev;
	sum += que.front().second * (que.front().first - 3);
	while(!que.empty()) {
		auto curr = que.front();
		que.pop();
		sum += curr.second;
		if (more) {
			sum += (curr.first - prev.first - 1) * curr.second;
		}
		prev = curr;
		more = true;
	}
	cout << sum;
	return 0;
}


