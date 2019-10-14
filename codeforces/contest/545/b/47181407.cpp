#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool str1[100001], str2[100001];
bool simi[100001];

vector<bool> vec;

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	string st1, st2;
	int n, z = 0;
	cin >> st1 >> st2;
	n = st1.length();
	if(st1 == st2) {
		for (int i = 0; i < n; ++i) {
			if(st1[i] == '1') {
				cout << '0';
			} else {
				cout << '1';
			}
		}
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		z += (st1[i] != st2[i]);
	}
	if( (z % 2 != 0) ) {
		cout << "impossible";
		return 0;
	}
	bool first = false;
	for (int i = 0; i < n; ++i) {
		if(st1[i] == st2[i]) {
			cout << st1[i];
		} else {
			if(first) {
				cout << st1[i]; first = false;
			} else {
				cout << st2[i]; first = true;
			}
		}
 	}
}
