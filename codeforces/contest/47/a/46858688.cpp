#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        if((i*(i+1))/2 == n) {
            cout << "YES";
            return 0;
        }
    }
   
    cout << "NO";
    return 0;
}