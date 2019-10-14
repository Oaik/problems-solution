#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define all(v)  	((v).begin()),((v).end())
#define sz(x)  		((int) (x).size())
#define clr(a,b)	memset(a,b,sizeof(a))
const double EPS = 1e-8;
const double pi = acos(-1);

int dcmp(double a, double b) {
	return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1;
}
void debug() {
	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);
}

int arr[100001] = {};
bool vis[100001] = {};

int main() {
	cout << fixed << setprecision(7);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n, r;
	cin >> n >> r;
	double a = (double)360/n, b;
	b = (180-a)/2;
	a = (a * pi / 180), b = b * pi / 180;
	cout << ((double)r*sin(a)) / ((2*sin(b)) - sin(a));
}
