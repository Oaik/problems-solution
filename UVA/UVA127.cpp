#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define all(v)    ((v).begin()),((v).end())
#define clr(a,b)  memset(a,b,sizeof(a))
const double EPS = 1e-8, pi = acos(-1);
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);  // freopen("output.in", "wt", stdout);
#endif
}

int const N = 2e5 + 9, OO = 1e9;

vector<stack<string>> vec(53);

int main() {
  cout << fixed << setprecision(12);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  debug();
  string str;
  while (cin >> str, str[0] != '#') {
    vec.clear();
    stack<string> st;
    st.push(str);
    vec.push_back(st);
    for (int i = 0; i < 51; ++i) {
      cin >> str;
      stack<string> st;
      st.push(str);
      vec.push_back(st);
    }
    for (int i = 1; i < (int)vec.size(); ++i) {
      if ((i >= 3) && (vec[i].top()[0] == vec[i - 3].top()[0] || vec[i].top()[1] == vec[i - 3].top()[1])) {
        vec[i - 3].push(vec[i].top());
        vec[i].pop();
        if (vec[i].empty())
          vec.erase(vec.begin() + i);
        i -= 4;
      } else if ( (i >= 1) && ((vec[i].top()[0] == vec[i - 1].top()[0]) || (vec[i].top()[1] == vec[i - 1].top()[1]))) {
        vec[i - 1].push(vec[i].top());
        vec[i].pop();
        if (vec[i].empty())
          vec.erase(vec.begin() + i);
        i -= 2;
      }
    }
    // printing
    cout << vec.size() << " pil" << ((vec.size() > 1) ? "es" : "e") << " remaining:";
    for (int i = 0; i < (int)vec.size(); ++i) {
      cout << " " << vec[i].size();
    }
    cout << endl;
  }
  return 0;
}

