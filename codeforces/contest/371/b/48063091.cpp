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

int cnt = 0;
void countDiv(int &num, int div) {
	while(num % div == 0) {
		num /= div;
		++cnt;
	}
}

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int a, b, gc;
	cin >> a >> b;
	gc = __gcd(a, b);
	a /= gc, b /= gc;
	countDiv(a, 2), countDiv(b, 2);
	countDiv(a, 3), countDiv(b, 3);
	countDiv(a, 5), countDiv(b, 5);
	if(a == b)
		cout << cnt;
	else
		cout << -1;
}
