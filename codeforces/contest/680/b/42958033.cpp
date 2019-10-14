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

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define ll long long

const double EPS = (1e-7);
int dcmp(double x, double y) {
	return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}

int n;

bool valid(int i) {
	return i < n && i >= 0;
}

using namespace std;

int main() {
	int a, cnt = 0;
	vector<int> dis;
	vector<int> cites;
	cin >> n >> a;
	cites = vector<int>(n);
	for (int i = 0; i < n; ++i) {
		cin >> cites[i];
		if (cites[i])
			dis.push_back(abs(a - i - 1));
	}
	for (int i = 0; i < (int)dis.size(); ++i) {
		if ((cites[a + dis[i] - 1] == 1 || !valid(a + dis[i] - 1))
				&& (cites[(a - dis[i]) - 1] == 1 || !valid((a - dis[i]) - 1))) {
			++cnt;
		}
	}
	cout << cnt;
	return 0;
}
