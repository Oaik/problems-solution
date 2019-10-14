#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	string str;
	cin >> str;
	int n = str.length();
	int mid = (n % 2 == 0) ? n/2 - 1: n/2;
	int left = mid-1, right = mid + 1;
	cout << str[mid];
	while(left >= 0 || right < n ) {
		if(right < n)
			cout << str[right];
		if(left >= 0)
			cout << str[left];
		left--, right++;
	}
	return 0;
}
