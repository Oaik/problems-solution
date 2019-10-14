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
	int a = 0, b = 0, c = 0;
	string inp;
	for (int i = 0; i < 3; ++i) {
		cin >> inp;
		if (inp[1] == '>') {
			if (inp[0] == 'A')
				++a;
			else if (inp[0] == 'B')
				++b;
			else
				++c;
		} else {
			if (inp[2] == 'A')
				++a;
			else if (inp[2] == 'B')
				++b;
			else
				++c;
		}
	}
	map<int,char> mymap;
	mymap.emplace(a,'A'),mymap.emplace(b,'B'),mymap.emplace(c,'C');
	if (mymap.size() < 3) cout << "Impossible";
	else
		for (auto& x: mymap)
			cout << x.second;
	return 0;
}
