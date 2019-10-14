#include <bits/stdc++.h>

using namespace std;

int r[10009];

int main() {
	int n, m;
	string str;
	cin >> n;
	while(n--) {
		cin >> m >> str;
		if(m == 1) {
			cout << 0 << endl;
			continue;
		}
		if(str[0] == '>' || str[m-1] == '<') {
			cout << 0 << endl;
			continue;
		}
		if(m <= 3) {
			cout << 1 << endl;
			continue;
		}
		int mx = m+1;
		for (int i = 1; i < m-1; ++i) {
			if(str[i] == '>') {
				mx = min(mx, i);
			} else {
				mx = min(mx, m-i-1);
			}
		}
		cout << max(mx, 0) << endl;
	}
}
