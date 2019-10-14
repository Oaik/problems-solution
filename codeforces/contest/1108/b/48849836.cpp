
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

int arr[130] ={};
int visited[10001] = {};
set<int> st;

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n, a, mx = 0;
	cin >> n;
	clr(visited, 0);
	for (int i = 0; i < n; ++i) {
		cin >> a;
		visited[a]++;
		st.insert(a);
		mx = max(a, mx);
	}
	int m = st.size(), j = 0;
	for(auto it: st) {
		arr[j] = it;
		++j;
	}
	for (int i = 1; i <= mx; ++i) {
		if(mx % i == 0) {
			visited[i]--;
		}
	}
	for (int i = mx; i > 0; --i) {
		if(visited[i] > 0) {
			cout << i << " " << mx;
			return 0;
		}
	}
	cout << mx << " " << mx;
	return 0;
}
