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
	vector<int> elm;
	vector<int> sorted;
	vector<int> checker;
	int k = 0, n, placeholder, start = 0, end = 0, curr = 0, holder = 1;
	scanf("%d", &n);
	elm = vector<int>(n);
	sorted = vector<int>(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &placeholder);
		elm[i] = placeholder;
		sorted[i] = placeholder;
	}
	sort(sorted.begin(), sorted.end());
	for (; k < n; ++k) {
		if (elm[k] != sorted[k]) {
			start = k;
			break;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (elm[i] == sorted[k]) {
			curr = i;
			break;
		}
	}

	reverse(elm.begin() + start, elm.begin() + 1 + curr);

	for(int i=0; i<n; i++)
		if(elm[i]!=sorted[i]){
			cout << "no\n";
			return 0;
		}

	cout << "yes\n" << start+1 << ' ' << curr+1 << endl;
	return 0;
}
