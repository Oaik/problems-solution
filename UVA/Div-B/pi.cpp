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
unsigned int gcd(unsigned int n1, unsigned int n2) {
	return (n2 == 0) ? n1 : gcd(n2, n1 % n2);
}

unsigned int nChoosek(unsigned int n, unsigned int k) {
	if (k > n)
		return 0;
	if (k * 2 > n) /*return*/
		k = n - k;  //remove the commented section
	if (k == 0)
		return 1;

	int result = n;
	for (unsigned int i = 2; i <= k; ++i) {
		result *= (n - i + 1);
		result /= i;
	}
	return result;
}

using namespace std;

unsigned int arr[51];
int main() {
	unsigned int n, numOfAllSets, counter = 0;
	while (cin >> n && n) {
		counter = 0;
		for (unsigned int i = 0; i < n; ++i)
			cin >> arr[i];
		sort(arr, arr+n);
		numOfAllSets = nChoosek(n,2);
		for (unsigned int i = 0; i < n-1; ++i) {
			for (unsigned int j = i+1; j < n; ++j) {
				if (gcd(arr[i], arr[j]) == 1)
					counter++;
			}
		}
		if (counter)
			cout << fixed << setprecision(6) << sqrt((numOfAllSets * 6.000000) / counter) << "\n";
		else cout << "No estimate for this data set.\n";
	}
}

