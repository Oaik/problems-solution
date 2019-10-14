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

int arr[100001];

int main() {
	vector<int> vec;
	vector<int> ele;
	int n, k, a;
	cin >> n >> k;
	ele.push_back(0);
	for (int i = 1; i <= n; ++i) {
		cin >> a;
		ele.push_back(a);
	}
	sort(ele.begin(), ele.end());
	for (int i = 0; i < n; ++i) {
		if(ele[i+1] - ele[i] > 0)
			vec.push_back(ele[i+1] - ele[i]);
	}
	int vecSize = sz(vec);
	if(k > vecSize) {
		for (int i = 0; i < vecSize; ++i)
			cout << vec[i] << "\n";
		for (int i = vecSize; i < k; ++i) {
			cout << 0 << "\n";
		}
	} else {
		for (int i = 0; i < k; ++i)
			cout << vec[i] << "\n";
	}
	return 0;
}
