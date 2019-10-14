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
	string inp;
	cin >> inp;
	if (inp == "0") {
		cout << 0;
		return 0;
	}
	int n = inp.length(), final = 0, sum = 0;
	while(n != 1) {
		++final;
		for (int i = 0; i < n; ++i) {
			sum += inp[i] - '0';
 		}
		inp = to_string(sum), sum = 0;
		n = inp.length();
	}
	cout << final;
	return 0;
}
