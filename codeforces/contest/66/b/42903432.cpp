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

using namespace std;

int main() {
	int n, cnt = 0, curr;
	vector<int> vec;
	vector<int> res;
	cin >> n;
	if (n == 1) {
		cout << 1;
		return 0;
	}

	vec = vector<int> (n);
	for (int i = 0; i < n; ++i) cin >> vec[i];

	for (int i = 0; i < n; ++i) {
		curr = vec[i], ++cnt;
		for (int j = i+1; j < n; ++j) {
			if (vec[j] <= curr) {
				++cnt, curr = vec[j];
			}
			else break;
		}
		curr = vec[i];
		for (int j = i-1; j >= 0; --j) {
			if (vec[j] <= curr) {
				++cnt, curr = vec[j];
			}
			else break;
		}
		res.push_back(cnt);
		cnt = 0;
	}
	auto it = max_element(std::begin(res), std::end(res));
	cout << *it;
	return 0;
}
