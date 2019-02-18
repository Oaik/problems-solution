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
	int t = 0,n = 0, m = 0, pn1, pn2, curr = 0, carry = 0;
	bool isZero = true;
	string pl1, pl2;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		isZero = true,n = 0, m = 0, curr = 0, carry = 0;
		cin >> pl1 >> pl2;
		pn1 = pl1.length(), pn2 = pl2.length();
		vector<int> vec1;
		vector<int> vec2;
		vector<int> result;
		while(pn1--) {
			vec1.push_back(pl1[curr++] - '0');
			++n;
		}
		curr = 0;
		while(pn2--) {
			vec2.push_back(pl2[curr++] - '0');
			++m;
		}
		curr = 0;
		for (int j = n-1; j >= 0; --j) {
			if (vec1[j] == 0) {
				vec1.pop_back();
				--n;
			} else break;
		}
		for (int j = m-1; j >= 0; --j) {
			if (vec2[j] == 0) {
				vec2.pop_back();
				--m;
			} else break;
		}
//		reverse(vec1.begin(), vec1.end());
//		reverse(vec2.begin(), vec2.end());
		if (m > n) {
			while(m > 0) {
				while(n > 0) {
					result.push_back((vec1[curr] + vec2[curr] + carry) % 10 );
					carry = (vec1[curr] + vec2[curr] + carry) / 10;
					--m, --n, ++curr;
				}
				if (m <= 0) {
					if (carry != 0)
						result.push_back(carry);
				}
				else result.push_back((vec2[curr] + carry) % 10);
				carry = ((vec2[curr] + carry) / 10), ++curr, --m;
				if (m == 0 && carry != 0) result.push_back(carry);
			}
		} else {
			while(n > 0) {
				while(m > 0) {
					result.push_back((vec1[curr] + vec2[curr] + carry) % 10 );
					carry = (vec1[curr] + vec2[curr] + carry) / 10;
					--m, --n, ++curr;
				}
				if (n <= 0) {
					if (carry != 0)
						result.push_back(carry);
				}
				else result.push_back((vec1[curr] + carry) % 10);
				carry = ((vec1[curr] + carry) / 10), ++curr, --n;
				if (n == 0 && carry != 0) result.push_back(carry);
			}
		}
		for(auto const& value: result) {
			if (value == 0 && isZero) {

			} else {
				isZero = false;
				cout << value;
			}
		}
		cout << "\n";
	}
}

