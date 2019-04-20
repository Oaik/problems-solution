#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define all(v)    ((v).begin()),((v).end())
#define clr(a,b)  memset(a,b,sizeof(a))
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
 freopen("output.txt", "wt", stdout);
#endif
cout << fixed << setprecision(0);
ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

int const N = 2e9 + 9, OO = 1e9;

bool isPrime(ull x) {
  if(x == 2)
    return 1;
  if(x % 2 == 0 || x == 1)
    return 0;
  for (ull i = 3; i * i <= x; i += 2)
  {
    if(x % i == 0)
      return 0;
  }
  return 1;
}

int main() {
  debug();
  ull n;
  while(cin >> n, n) {
    if(!isPrime(n)) {
      cout << "Given number is NOT prime! NO perfect number is available." << endl;
      continue;
    }
    if(isPrime(pow(2, n) - 1)) {
   	n = pow(2, n-1) * (pow(2, n) - 1);
    	cout << "Perfect: " << n <<'!' << endl;      
    } else {
	cout << "Given number is prime. But, NO perfect number is available." << endl;
    }
   
  }
}

