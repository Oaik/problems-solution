#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll n;
    cin >> n;
    if(n == 0) {
        cout << 0;
        return 0;
    }
    if(n % 2 != 0)
        n = (n+1)/2;
    else
        ++n;
    cout << n;
}