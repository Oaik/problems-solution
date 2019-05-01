#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;
ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}


// Complete the towerColoring function below.
ll towerColoring(ull n) {
        ll p = 1e9 + 7;

    ll yy = (power(3, n, p - 1)) % (p-1);
  ll res = power(3, yy, p) % p;
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    ll n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    ll result = towerColoring(n);

    fout << result << "\n";

    fout.close();

    return 0;
}

