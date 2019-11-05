#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin)
#define write freopen("output.in", "wt", stdout)
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, M = 5e4 + 9, OO = 1e9 + 1, MOD = 1e9 + 7;
const ll inf = 1e18;

ll calc(ll mid) {
  ll lo = 1, hi = 9;
  ll res = 0, fact = 1;
  ll prv = 0;
  while(lo <= mid) {
    ll m = (min(mid, hi) - lo + 1);
    res += ((m * (m + 1)) / 2) * fact;

    res += m * prv;

    ll tt = (hi - lo + 1) * (hi - lo + 1 + 1) / 2 * fact;
    ll tt2 = (hi- lo) * (hi - lo + 1) / 2 * fact;
    prv += (tt - tt2);

    lo *= 10, hi *= 10;
    hi += 9,++fact;
  }
  return res;
}

ll calcDig(ll mid) {
  ll lo = 1, hi = 9, fact = 1;
  ll res = 0;
  while(lo <= mid) {
    res += (min(mid, hi) - lo + 1) * fact;

    lo *= 10, hi *= 10;
    hi += 9,++fact;
  }
  return res;
}

int main() {
  fastIO;
  int q;
  cin >> q;
  while(q--) {
    ll a;
    cin >> a;
    ll start = 0, end = 5e8, mid = 0, ans;
//    cerr << calc(end) << endl;
    while(start <= end) {
      mid = start + (end - start) / 2;
      ll can = calc(mid);
      if(can < a) {
        start = mid + 1;
        ans = can;
      } else {
        end = mid - 1;
      }
    }
//    cerr << ans << endl;
    ll diff = a - ans;
    bool lsa = 1;
    ll ee = 1e17, ss = 0, mm = 0, bestVal = 0, elValA5ern = -1;
    while(ss <= ee) {
      mm = ss + (ee - ss) / 2;
      ll rr = calcDig(mm);
      if(rr <= diff) {
        ss = mm + 1;
        elValA5ern = mm;
        bestVal = rr;
        if(rr == diff) {
          lsa = 0;
          break;
        }
      } else {
        ee = mm - 1;
      }
    }
    if(!lsa) {
      cout << to_string(elValA5ern).back() << endl;
      continue;
    }
    ll finalDiff = diff - bestVal - 1;
    ll cur = elValA5ern + 1;
    while(1) {
      string str = to_string(cur);
      if(finalDiff < str.size()) {
        cout << str[finalDiff] << '\n';
        break;
      }
      finalDiff -= str.size();
      ++cur;
    }
  }
  return 0;
}

