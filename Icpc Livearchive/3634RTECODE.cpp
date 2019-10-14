#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin)
#define write freopen("output.in", "wt", stdout)
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, M = 3e4 + 9, OO = 1e9 + 1, MOD = 1e9 + 7;
const ll inf = 1e18;

int main() {
  fastIO;
  int t, n;
  cin >> t;
  string str;
  while(t--) {
    cin >> n;
    stack<vector<string>> st;
    while(n--){
      cin >> str;
      vector<string> A,B;
      if(str == "PUSH") {
        st.push(A);
        cout << 0 << endl;
      } else if(str == "DUP") {
        A = st.top();
        st.pop();
        cout << A.size() << endl;
        st.push(A);
        st.push(A);
      } else if(str == "ADD") {
        B = st.top();
        st.pop();
        A = st.top();
        st.pop();
        sort(all(A));
        sort(all(B));
        vector<string> addVec;
        int m = B.size();
        for (int i = 0; i < m; ++i)
          addVec.push_back(B[i]);
        string nwA;
        nwA.push_back('{');
        m = A.size();
        for (int i = 0; i < m; ++i)
          nwA += A[i];
        nwA.push_back('}');
        addVec.push_back(nwA);
        sort(all(addVec));
        st.push(addVec);
        cout << addVec.size() << endl;
      } else if(str == "UNION") {
        set<string> U;
        A = st.top();
        st.pop();
        B = st.top();
        st.pop();
        for(string it: A)
          U.insert(it);
        for(string it: B)
          U.insert(it);
        vector<string> nwU;
        for(string it: U)
          nwU.push_back(it);
        st.push(nwU);
        cout << nwU.size() << endl;
      } else if(str == "INTERSECT") {
        A = st.top();
        st.pop();
        B = st.top();
        st.pop();
        map<string, int> mp;
        vector<string> nwI;
        for(string it: A)
          ++mp[it];
        for(string it: B)
          ++mp[it];
        for(auto it: mp)
          if(it.second == 2)
            nwI.push_back(it.first);
        st.push(nwI);
        cout << nwI.size() << endl;
      }
    }
    cout << "***" << endl;
  }
  return 0;
}

