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
const ll INF = 1e9;
int dcmp(double x, double y) {
	return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}

int main() {
	vector<pair<int, int>> vec1;
	vector<pair<int, int>> vec2;
	int p, q, l, r, a, b, getUpTime = 0, counter = 0;
	bool found = false;
	scanf("%d%d%d%d", &p, &q, &l, &r);
	getUpTime = r - l;
	for (int i = 0; i < p; ++i) {
		scanf("%d%d", &a, &b);
		vec1.push_back( { a, b });
	}
	for (int i = 0; i < q; ++i) {
		scanf("%d%d", &a, &b);
		vec2.push_back( { a, b });
	}
	for (int i = l; i <= r; ++i) {
		found = false;
		for (int j = 0; j < p && !found; ++j) {
			for (int k = 0; k < q; ++k) {
				if ( (vec2[k].first + i >= vec1[j].first && vec2[k].first + i <= vec1[j].second) || ((vec2[k].second + i >= vec1[j].first && vec2[k].second + i <= vec1[j].second)) ) {
					++counter, found = true;
					break;
				}
				if ((vec1[j].first >= vec2[k].first + i && vec1[j].first <= vec2[k].second + i) || (vec1[j].second >= vec2[k].first + i && vec1[j].second<= vec2[k].second + i)){
					++counter, found = true;
					break;
				}
			}
		}
	}
	cout << counter;
}
