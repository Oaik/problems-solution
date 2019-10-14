#include <bits/stdc++.h>

using namespace std;
#define ll long long

const double EPS = 1e-8;
int dcmp(double a, double b) {
	return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1;
}

int arr[100];

int main() {
//	freopen("input.in", "r", stdin);
//	freopen("output.in", "w", stdout);
	// [] t {}
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, i;
    cin >> n;
    --n;
    for (int j = 0; j < n; ++j) {
		cin >> arr[j];
	}
    cin >> arr[n];
    if(arr[0] > 15) {
    	cout << 15;
    	return 0;
    }
    for ( i = 0; i < n; ++i) {
		if(arr[i+1] - arr[i] > 15)
			break;
	}
    if(arr[i] >= 75)
    	cout << 90;
    else
    	cout << arr[i] + 15;
	return 0;
}
