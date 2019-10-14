#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define all(v)  	((v).begin()),((v).end())
#define sz(x)  		((ll) (x).size())
#define clr(a,b)	memset(a,b,sizeof(a))
const double EPS = 1e-8;
const double pi = acos(-1);
ll dcmp(double a, double b) {
	return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1;
}
void debug() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "rt", stdin);
//	freopen("output.in", "wt", stdout);
#endif
}

int const N = 1000 + 9, M = 100 + 9, OO = 1e9;

int main() {
	cout << fixed << setprecision(2);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	string str1, str2;
	cin >> str1 >> str2;
	int a, b;
	a = str1.find(':'), b = str2.find(':');
	int h1 = stoi(str1.substr(0, a)), m1 = stoi(str1.substr(a + 1));
	int h2 = stoi(str2.substr(0, b)), m2 = stoi(str2.substr(b + 1));
	int ht = h1 + h2, mt = 0;
	if (ht & 1) {
		mt += 30;
	}
	ht /= 2;
	int mtt = (m1 + m2) / 2;
	int mq = mtt + mt;
	if(mq >= 60) {
		mq -= 60;
		++ht;
	}
	if(ht <= 9)
		cout << '0';
	cout << ht << ":";
	if(mq <= 9)
		cout << '0';
	cout << mq;
	//	cout << ans;
}
