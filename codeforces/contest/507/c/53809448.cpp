#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);  //freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
double const EPS = 1e-9, PI = acos(-1);
int const N = 1e5 + 9, M = 1e5 + 9, OO = 1e9;

ll prefix[59];
vector<char> vec;
void prefixer() {
  prefix[0] = 1;
  for (int i = 1; i < 51; ++i) {
    ll cur = pow(2, i);
    prefix[i] += cur + prefix[i - 1];
  }
}
char a3ksEl7rf(char c) {
  if(c == 'L')
    return 'R';
  return 'L';
}

int main() {
  debug();
  prefixer();
  ll h, n;
  cin >> h >> n;
  ll curNode = prefix[h];
  curNode -= (pow(2, h) - n);
  while (curNode != 1) {
    if (curNode & 1)
      vec.push_back('R');
    else
      vec.push_back('L');
    curNode /= 2;
  }
  reverse(all(vec));
  char move = 'L';
  ll total = 0;
  int z = vec.size();
  for (int i = 0; i < z; ++i) {
    if (move == vec[i])
      ++total, move = a3ksEl7rf(move);
    else
      total += pow(2, z - i);
  }
  cout << total;
}
