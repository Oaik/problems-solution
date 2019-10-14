#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <iomanip>
//#include <complex>

using namespace std;

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define clr(arr, k) (memset(arr, k, sizeof(arr)))
#define lpv(i,a,n) 	for(int i=a;i<(int)n;i++)
#define ll long long

//#define X real()
//#define Y imag()
//typedef complex<double> point;
//
//#define angle(a)  (atan2((a).Y, (a).X))
//#define dp(a, b)  ((conj(a) * (b)).real())
//#define cp(a, b)  ((conj(a) * (b)).imag())
//#define length(a) (dp(a, a))
//#define rotate0(p, ang) ((p) * exp(point(0, ang)))
//#define rotateA(p, ang, about) ((rotate0(p, ang)) + about)
//#define reflect0(v, m) (conj((v) / (m)) * (m))

const double EPS = (1e-7);
const double PI = acos(-1.0);
const ll INF = 1e9;

int dcmp(double x, double y) {
	return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

void contest() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

ll arr[1000001];
bool cut[1000001] = {0};
bool visited[1000001] = {0};

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	ll n, m, l, t, p, d, cnt = 0;
//	bool visited = false;
	int last = -1;
	cin >> n >> m >> l;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		if (arr[i] > l) {
			if(i - last > 1) ++cnt;
			cut[i] = 1, visited[i] = 1;
			last = i;
		}
	}
//	for (int i = 1; i <= n; ++i) {
//		if(( i == 1 || cut[i-1] == 0 ) && (cut[i] == 1) )
//			++cnt;
//	}
	for (int i = 0; i < m; ++i) {
		cin >> t;
//		visited = false;
		if (t) {
			cin >> p >> d;
			arr[p] += d;
			if (arr[p] > l && !cut[p]) {
				cut[p] = 1, visited[p] = 1;
				if( (cut[p+1] == 0 || p == n) && (cut[p-1] == 0 || p == 1))
					++cnt;
				else if (cut[p+1] == 1 && cut[p-1] == 1)
					--cnt;
			}
		} else {
			cout << cnt << "\n";
		}
	}
	return 0;
}
