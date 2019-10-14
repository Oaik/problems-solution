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

int visited[100001] = {0};
int main() {
	int n, a, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		visited[a] = 1;
		if (visited[n - cnt]) {
			while(visited[n - cnt]) {
				cout << n-cnt << " ";
				++cnt;
			}
		}
		cout << endl;
	}
	return 0;
}
