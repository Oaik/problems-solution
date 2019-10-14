#include <bits/stdc++.h>
using namespace std;

int main() {
	string inp, cmp, result;
	cin >> inp >> result;
	cmp = inp;
	int n = inp.length();
	for (int i = 0; i < n; ++i)
		cmp[i] = inp[n-i-1];
	if (cmp == result)
		cout << "YES";
	else
		cout << "NO";
}
