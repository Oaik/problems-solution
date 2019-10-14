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

int elements[150001];

int main() {
	int n, k, index = 0,back = 0, j = 0, curr = 0;
	cin >> n >> k;
	vector<int>indexes;
	for (; j < k; ++j) {
		cin >> elements[j];
		curr += elements[j];
	}
	indexes.push_back(curr);
	for (;j < n; ++j) {
		cin >> elements[j];
		curr -= elements[back++];
		curr += elements[j];
		indexes.push_back(curr);
	}
	int minimal = indexes[0];
	for (int i = 0; i < n+1-k; ++i) {
		if (minimal > indexes[i]) {
			minimal = indexes[i];
			index = i;
		}
	}
	cout << index + 1;
}
