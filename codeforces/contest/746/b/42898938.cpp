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
	vector<char> vec;
	string inp;
	int n;
	cin >> n >> inp;
	if (n <= 2) {
		cout << inp;
		return 0;
	}
	int counter = 0, start = 0, end = n - 1;
	vec = vector<char>(n);
	for (int i = inp.length() - 1; counter < n; i-=2) {
		vec[end] = inp[i], vec[start] = inp[i-1];
		counter += 2, --end, ++start;
		if (n-counter == 1) {
			vec[end] = inp[i-2];
			break;
		}
	}
	for (auto i = vec.begin(); i != vec.end(); ++i)
		cout << *i;

	return 0;
}
