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

ll nums[10] = {};

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n, i;
	char b;
	cin >> n;
	for (int j = 0; j < n; ++j) {
		cin >> b;
		i = (int) (b - '0');
		if (i == 9) {
			nums[2] += 7;
			nums[3] += 4;
			nums[5]++;
			nums[7]++;
		} else if (i == 8) {
			nums[2] += 7;
			nums[3] += 2;
			nums[5]++;
			nums[7]++;
		} else if (i == 7) {
			nums[2] += 4;
			nums[3] += 2;
			nums[5]++;
			nums[7]++;
		} else if (i == 6) {
			nums[2] += 4;
			nums[3] += 2;
			nums[5]++;
		} else if (i == 5) {
			nums[2] += 3;
			nums[3]++;
			nums[5]++;
		} else if (i == 4) {
			nums[2] += 3;
			nums[3]++;
		} else if (i == 3) {
			nums[2]++;
			nums[3]++;
		} else if (i == 2) {
			nums[2]++;
		}
	}

	for (i = 9; i >= 2; --i) {
		while (nums[i] > 0) {
			if (i == 9) {
				cout << 9;
				nums[9]--;
				nums[2] -= 7;
				nums[3] -= 4;
				nums[5]--;
				nums[7]--;
			} else if (i == 7) {
				cout << 7;
				nums[2] -= 4;
				nums[3] -= 2;
				nums[5]--;
				nums[7]--;
			} else if (i == 5) {
				cout << 5;
				nums[2] -= 3;
				nums[3]--;
				nums[5]--;
			} else if (i == 3) {
				cout << 3;
				nums[2]--;
				nums[3]--;
			} else {
				cout << 2;
				nums[2]--;
			}
		}
//		cout << nums[i] << " ";
	}
}
