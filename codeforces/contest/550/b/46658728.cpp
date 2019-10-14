#include <bits/stdc++.h>

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define clr(arr, k) (memset(arr, k, sizeof(arr)))
#define ll long long

using namespace std;

int arr[20];
int n, l, r, x, answer = 0;

int sol(int mini, int maxi, int sumi, int indxi) {
	if(indxi == n) {
		if(sumi >= l && sumi <= r && maxi - mini >= x)
			++answer;
		return 0;
	}
	sol(mini, maxi, sumi, indxi + 1);
	sol(min(mini, arr[indxi]), max(maxi, arr[indxi]), sumi + arr[indxi], indxi + 1);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	cin >> n >> l >> r >> x;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	sol(INT_MAX, 0, 0, 0);
	cout << answer;
	return 0;
}
