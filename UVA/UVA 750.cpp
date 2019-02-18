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

int currow, curcol, sol = 0;
int dataset[8];
bool dig1[65] = {}, col[8] = {};
map<int, bool> dig2;

void backtracking(int idx = 0) {
	// base case
	if(idx == 8) {
		if(sol >= 9) {
			cout << sol+1 << "      ";
		} else
			cout << " " << sol+1 << "      ";
		cout << dataset[0] + 1;
		for (int i = 1; i < 8; ++i) {
			cout << " " << dataset[i] + 1;
		}
		cout << "\n";
		++sol;
	}

	if(idx == currow)
		return backtracking(idx+1);

	for (int i = 0; i < 8; ++i) {
		if(!dig1[idx+i] && !col[i] && !dig2[i-idx]) {
			// choose
			dig1[idx+i] = col[i] = dig2[i-idx] = 1;
			dataset[idx] = i;

			//explore
			backtracking(idx+1);

			// unchoose
			dig1[idx+i] = col[i] = dig2[i-idx] = 0;
		}
	}
}

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t;
//	debug();
	cin >> t;
	while(t--) {
		cout << "SOLN       COLUMN\n";
		cout << " #      1 2 3 4 5 6 7 8\n\n";
		sol = 0;
		clr(dataset, 0);
		clr(col, 0);
		cin >> curcol >> currow;
		dataset[--currow] = --curcol;
		dig1[currow+curcol] = col[curcol] = dig2[curcol-currow] = 1;
		backtracking();
		dig1[currow+curcol] = col[curcol] = dig2[curcol-currow] = 0;
		if(t != 0)
			cout << "\n";
	}
}

