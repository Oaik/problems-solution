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
using namespace std;

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define ll long long

const double EPS = (1e-7);
const ll INF = 1e9;
int dcmp(double x, double y) {
	return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}

int main() {
	int n, a;
	set<int> nums;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a);
		nums.insert(a);
	}
	if (nums.size() > 3) {
		cout << "NO";
		return 0;
	} else if (nums.size() == 3) {
		auto it = nums.begin();
		int first = *it, second = *(++it), third = *(++it);
		if (third - second == second-first ) {
			cout << "YES";
			return 0;
		} else {
			cout << "NO";
			return 0;
		}
	} else {
		cout << "YES";
		return 0;
	}
}

