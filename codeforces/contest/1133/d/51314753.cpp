/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author omar
 */

#include <iostream>
#include <fstream>

#include <bits/stdc++.h>

int const N = 2e5 + 9, M = 100 + 9, OO = 1e9;

using namespace std;

int arr1[N], arr2[N];
class DZeroQuantityMaximization {
public:
	void solve(std::istream& in, std::ostream& out) {
		std::map<std::pair<int, int>, int> mp;
		int n;
		in >> n;
		for (int i = 0; i < n; ++i) {
			in >> arr1[i];
		}
		for (int i = 0; i < n; ++i) {
			in >> arr2[i];
		}
		int g,a,b, mx = 0, cnt = 0;
		for (int i = 0; i < n; ++i) {
			g = std::__gcd(arr1[i], arr2[i]);
			if(g == 0) {
				++cnt;
				continue;
			}
			b = arr2[i]/g, a = arr1[i]/g;
			if(a == 0)
				continue;
			if(b == 0) {
				++mp[{0,0}];
				mx = max(mx, mp[{0, 0}]);
			} else {
				++mp[{-b, a}];
				mx = max(mx, mp[{-b, a}]);
			}
		}
		out << mx + cnt;
	}
};


int main() {
	DZeroQuantityMaximization solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}
