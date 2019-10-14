#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<int> idx1;
vector<int> idx2;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(0);
	string str;
	int n, numTwo = -1, ones = 0;
	bool startWithTwo = false;
	cin >> str;
	if(str[0] == '2')
		startWithTwo = true;
	n = str.length();
	for (int i = 0; i < n; ++i) {
		if(str[i] == '1')
			++ones;
	}
	str.erase(std::remove(str.begin(), str.end(), '1'), str.end());
	n = str.length();
	for (int i = 0; i < n; ++i) {
		if( str[i] == '2') {
			numTwo = i;
			break;
		}
	}
	n = str.length();
	if(numTwo != -1) {
		for (int i = 0; i < numTwo; ++i)
			cout << str[i];
		for (int i = 0; i < ones; ++i) {
			cout << '1';
		}
		for (int i = numTwo; i < n; ++i) {
			cout << str[i];
		}
	} else {
		for (int i = 0; i < n; ++i)
			cout << str[i];
		for (int i = 0; i < ones; ++i) {
			cout << '1';
		}
	}
	return 0;

	cout << str;
}
