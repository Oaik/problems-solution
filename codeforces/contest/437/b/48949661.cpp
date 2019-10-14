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

vector<int> vec;

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int sum, limit;
	cin >> sum >> limit;
	int cur = limit, num = cur, cnt = 0;
	while(cur && sum) {
		if(cur & 1) {
			vec.push_back(cur);
			sum--;
			cur--;
			continue;
		}
		num = cur;
		cnt = 0;
		while(!(num & 1)) {
			++cnt;
			num >>= 1;
		}
		cnt = pow(2, cnt);
		if(cnt <= sum) {
			vec.push_back(cur);
			sum -= cnt;
		}
		--cur;
	}
	if(sum != 0) {
		cout << "-1\n";
	} else {
		cout << vec.size() << "\n";
		for(auto it: vec)
			cout << it << " ";
	}
}
