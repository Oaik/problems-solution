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

set<int> s;
vector<int> res;
bool done = true;

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n, a;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		a = (i*2)%n;
		if(s.find(a) == s.end()) {
			s.insert(a);
			res.push_back(a);
		} else {
			done = false;
			break;
		}
	}
	if(done) {
		for (int i = 0; i < n; ++i)
			cout << i << " ";
		cout << "\n";
		for (int i = 0; i < n; ++i)
			cout << i << " ";
		cout << "\n";
		for(int it: res)
			cout << it << " ";
	} else
		cout << "-1";
}
