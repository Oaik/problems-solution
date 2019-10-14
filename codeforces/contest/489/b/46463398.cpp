#include <bits/stdc++.h>

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define clr(arr, k) (memset(arr, k, sizeof(arr)))
#define lpv(i,a,n) 	for(int i=a;i<(int)n;i++)
#define ll long long

using namespace std;

const double EPS = (1e-8);
const double PI = acos(-1.0);
const ll INF = 1e9;

int dcmp(double x, double y) {
	return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}
void contest() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);
#endif
}

using namespace std;

int boys[101], girls[101];
bool visited[101] = {0};

int main() {
	int n, m, i = 0, counter = 0;
	clr(girls, INF);
	cin >> n;
	for (i = 0; i < n; ++i) {
		cin >> boys[i];
	}
	cin >> m;
	for (i = 0; i < m; ++i) {
		cin >> girls[i];
	}
	sort(boys, boys+n), sort(girls, girls+m);
	int low, high;
	for (int i = 0; i < n; ++i) {
		low = (lower_bound(girls, girls+m, boys[i]-1)) - girls;
		high = (upper_bound(girls, girls+m, boys[i]+1)) - girls;
//		cout << low << " " << high << endl;
		for (; low <= high; low++) {
			if(!visited[low] && abs(boys[i] - girls[low]) <= 1) {
				visited[low] = 1;
				++counter;
				break;
			}
		}
	}
	cout << counter;
	return 0;
}
