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

int arr[6];
bool found = false;
bool visited[6] = {};

void backtracking(int cur = 0,int sum = INT_MAX) {
	if(cur == 5 && sum == 23)
		found = true;
	if(found)
		return;
	if(cur == 5)
		return;
	for (int i = 0; i < 5; ++i) {
		if(!visited[i]) {
			visited[i] = 1;
			if(sum == INT_MAX) {
				backtracking(cur+1, arr[i]);
			} else {
				backtracking(cur+1, sum + arr[i]);
				backtracking(cur+1, sum - arr[i]);
				backtracking(cur+1, sum * arr[i]);
			}
			visited[i] = 0;
		}
	}
}

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
//	debug();
	while( (cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4]) && (arr[0] != 0 && arr[1] != 0 && arr[2] != 0 && arr[3] != 0 && arr[4] != 0) ) {
		found = false;
		backtracking();
		if(found)
			cout << "Possible\n";
		else
			cout << "Impossible\n";
	}
}

