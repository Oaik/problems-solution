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

bool arr[5001][5001] = {};
bool colours[5001] = {};
int inp[5001];

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n, a, m;
	bool done = true, found = false;
	cin >> n >> a;
	for (int i = 0; i < n && done; ++i) {
		cin >> m;
		found = false;
		for (int j = 0; j < a; ++j) {
			if(!arr[m][j] && !colours[j]) {
				arr[m][j] = 1;
				colours[j] = 1;
				inp[i] = j+1;
				found = true;
				break;
			}
		}
		for (int j = 0; j < a && !found; ++j) {
			if(!arr[m][j]) {
				arr[m][j] = 1;
				colours[j] = 1;
				inp[i] = j+1;
				found = true;
				break;
			}
		}
		if(!found) {
			done = false;
			break;
		}
	}
	if(!done) {
		cout << "NO";
	} else {
		cout << "YES\n";
		for (int i = 0; i < n; ++i) {
			cout << inp[i] << " ";
		}
	}
}
