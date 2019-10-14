#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define all(v)  	((v).begin()),((v).end())
#define sz(x)  		((int) (x).size())
#define clr(a,b)	memset(a,b,sizeof(a))
const double EPS = 1e-8;

int dcmp(double a, double b) {
	return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1;
}
void debug() {
	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);
}

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	string str;
	int n, m, q = 0, a = 0, len;
	cin >> str >> n;
	m = len = str.length();
	q = count(str.begin(), str.end(), '?'), a = count(str.begin(), str.end(), '*');
	m -= (q + a);
	if(m != n) {
		if(n > m) {
			if(m + a < n) {
				if(a == 0) {
					cout << "Impossible";
					return 0;
				}
				string res = "";
				for (int i = 1; i < len && n > m; ++i) {
					if(str[i] == '*') {
						int z = n - m;
						res = str.substr(0, i);
						for (int j = 0; j < z; ++j){
							++m;
							res = res + str[i-1];
						}
						res += str.substr(i, len - i);
						str = res;
						break;
					}
					if(str[i] == '?')
						str.erase(str.begin() + i), --i;
				}
			} else {
				while(m != n) {
					for (int i = 1; i < len && n > m; ++i) {
						if(str[i] == '*')
							++m, str[i] = str[i-1];
						if(str[i] == '?')
							str.erase(str.begin() + i), --i;
					}
				}
			}
		}
		else {
			if(a + q < m - n) {
				cout << "Impossible";
				return 0;
			} else {
				while(m != n) {
					for (int i = 1; i < len && n < m; ++i) {
						if(str[i] == '*' || str[i] == '?')
							--m, str[i-1] = ' ';
					}
				}
			}
		}
	}
	for(char letter: str) {
		if(letter != '?' && letter != '*' && letter != ' ')
			cout << letter;
	}
}
