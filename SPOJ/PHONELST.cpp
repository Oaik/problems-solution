#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read(v) freopen(v, "rt", stdin)
#define fastIO cout << fixed << setprecision(9), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e4 + 9, M = 1e6 + 1, OO = 1e9 + 1, MOD = 1e9 + 7;
const ll inf = 2e18;

string str[N];
int arr[N];
vector<vector<int>> tree;
vector<int> isLeaf;
bool can = 1;

int add() {
  tree.push_back(vector<int>(10, -1));
  isLeaf.push_back(0);
  return isLeaf.size() - 1;
}

void clear() {
  iota(arr, arr+N, 0);
  tree.clear();
  isLeaf.clear();
  add();
  can = 1;
}

void insert(string str) {
  int cur = 0;
  for (int i = 0; i < (int)str.size(); ++i) {
    int num = str[i] - '0';
    int nxt = tree[cur][num];
    if(nxt == -1)
      nxt = add();
    tree[cur][num] = nxt;
    cur = nxt;
    if(isLeaf[cur])
      can = 0;
  }
  isLeaf[cur] = 1;
}
bool cmp(int a, int b) {
  return str[a] < str[b];
}

int main() {
  fastIO;
  int t;
  cin >> t;
  while (t--) {
    clear();
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
      cin >> str[i];
    sort(arr, arr + n, cmp);
    for (int i = 0; i < n; ++i) {
      int idx = arr[i];
      insert(str[idx]);
    }
    if(can)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}

