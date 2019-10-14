#include <bits/stdc++.h>
using namespace std;

set<char> numbers;

int main() {
	int n, k, counter = 0 ,j = 0, bad = 0;
	string num;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		if (num.length() <= k) continue;
		for (; j < (int)num.length(); ++j)
			numbers.emplace(num[j]);
		for (int i=0; i<=k; ++i) {
			if ( numbers.count(i + '0')==0 ) {
				++bad;
				break;
			}
		 }
		if (!bad) ++counter;
		numbers.clear();
		j = 0,bad = 0;
	}
	cout << counter;
}

