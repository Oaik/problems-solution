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

char iterate[4] = { 'G', 'B', 'I', 'V' };
char colors[7] = { 'R', 'O', 'Y', 'G', 'B', 'I', 'V' };
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < 7; ++i) cout << colors[i];
	int m = n-7;
	for (int i = 0; i < m; ++i) {
		cout << iterate[i%4];
	}
}
