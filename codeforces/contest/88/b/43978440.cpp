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

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define ll long long

const double EPS = (1e-7);
int dcmp(double x, double y) {
	return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}
using namespace std;

vector<vector<pair<int, int>>> arr(27);

int main() {
	vector<pair<int, int>> shifts;
	int n, m, x, q, clicked = 0, req = 0;
	char text;
	int shift = 0, curr = 1, startShift = 0;
	bool noShift = 0;
	scanf("%d%d%d", &n, &m, &x);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf(" %c", &text);
			if (text == 'S') {
				shift++;
				shifts.push_back(make_pair(i, j));
			} else arr[text - 'a'].push_back(make_pair(i, j));
		}
		if (shift == m *2 && curr == i ) {
			shifts.erase(shifts.begin() + (curr - 1), shifts.begin() + (curr + m - 1));
			shift -= m;
			curr++;
		}
	}
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		scanf(" %c", &text);
		if (text < 96) {
			text = text + 32;
			auto got = arr[text - 'a'];
			if (got.empty() || !shift) {
				printf("%d", -1);
				return 0;
			} else {
				for (int k = startShift; k < shift && !noShift; ++k) {
					for (int z = 0; z < (int)got.size(); ++z) {
						if ( sqrt(pow(got[z].first - shifts[k].first, 2) + pow( got[z].second  - shifts[k].second, 2) ) <= x ) {
							noShift = 1;
							break;
						}
					}
					if (noShift) break;
				}
				if (!noShift)
					++clicked;
				noShift = 0;
			}
		} else {
			auto got = arr[text - 'a'];
			if (got.empty()) {
				printf("%d", -1);
				return 0;
			}
		}
	}
	printf("%d", clicked);
}
