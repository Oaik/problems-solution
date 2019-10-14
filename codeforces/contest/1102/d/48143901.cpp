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

deque<int> one, two, zero;

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n, twos = 0, ones = 0, zeros = 0, m;
	string str;
	cin >> n >> str;
	m = n / 3;
	for (int i = 0; i < n; ++i) {
		if(str[i] == '0') {
			zero.push_back(i);
		} else if(str[i] == '1') {
			one.push_back(i);
		} else {
			two.push_back(i);
		}
	}
	zeros = zero.size(), ones = one.size(), twos = two.size();
	while(zeros != m || ones != m || twos != m) {
		if(zeros < m) {
			if(ones > m) {
				str[one[0]] = '0';
				one.pop_front();
				--ones, ++zeros;
			} else {
				str[two[0]] = '0';
				two.pop_front();
				--twos, ++ zeros;
			}
		} else if(twos < m) {
			if(zeros > m) {
				str[zero[zero.size() - 1]] = '2';
				zero.pop_back();
				++twos, --zeros;
			} else {
				str[one[one.size() - 1]] = '2';
				one.pop_back();
				++twos, --ones;
			}
		} else {
			if(twos > m) {
				str[two[0]] = '1';
				two.pop_front();
				--twos, ++ones;
			} else {
				str[zero[zero.size() - 1]] = '1';
				zero.pop_back();
				--zeros, ++ones;
			}
		}
	}
	cout << str;
}
