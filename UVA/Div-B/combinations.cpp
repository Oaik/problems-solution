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

int main() {
	ll n, m;
	ll diff, total = 1, factm = 1,counter = 0, dff;
	while (cin >> n >> m && n) {
		total = 1, factm = 1,counter = 0;
		diff = n - m;
		if (diff > m) {
			for (int i = n; i > diff; --i) {
				total *= i;
				if (total % (m-counter) == 0) {
					total /= m-counter;
					counter++;
				}
			}
			dff = m-counter;
			for (int i = 1; i <= dff; ++i)
				factm *= i;
			total /= factm;
		} else {
			for (int i = n; i > m; --i) {
				total *= i;
				if (total % (diff-counter) == 0) {
					total /= diff-counter;
					counter++;
				}
			}
			dff = diff-counter;
			for (int i = 1; i <= dff; ++i)
				factm *= i;
			total /= factm;
		}
		cout << n << " things taken " << m << " at a time is " << total
				<< " exactly.\n";
	}
}

