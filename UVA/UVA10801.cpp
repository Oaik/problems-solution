#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, OO = 1e9;

int lvlCost[5], store[100][5];
int distt[100][5];
vector<vector<int>> vec;

struct edge {
  int num, lvl;ll cost;
  edge(int num, int lvl, ll cost) {
    this->num = num;
    this->lvl = lvl;
    this->cost = cost;
  }
  bool operator <(const edge &e) const {
    return cost > e.cost;
  }
};

//vector<vector<vector<edge>>> vv;
vector<edge> vv[100][5];

int main() {
  debug();
  int n, dist, num;
  string str, word;
  while (cin >> n >> dist) {
    for (int i = 0; i < n; ++i)
      cin >> lvlCost[i];
    cin.ignore();
    vec = vector<vector<int>>(n);
    for (int i = 0; i < 100; ++i) {
      for (int j = 0; j < 5; ++j)
        vv[i][j].clear();
    }
    for (int i = 0; i < n; ++i) {
      getline(cin, str);
      stringstream ss(str);
      while (ss >> word) {
        num = stoi(word);
        store[num][i] = num;
//        if (num == dist)
//          distLvl.push_back(i);
        vec[i].push_back(num);
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < (int) vec[i].size() - 1; ++j) {
        vv[vec[i][j]][i].push_back(edge(vec[i][j + 1], i, abs(vec[i][j + 1] - vec[i][j]) * lvlCost[i]));
        vv[vec[i][j + 1]][i].push_back(edge(vec[i][j], i, abs(vec[i][j + 1] - vec[i][j]) * lvlCost[i]));
      }
    }
    for (int i = 0; i < n - 1; ++i) {
      for (int j = 0; j < (int) vec[i].size(); ++j) {
        for (int k = i+1; k < n; ++k) {
          if (find(all(vec[k]), vec[i][j]) != vec[k].end()) {
            vv[vec[i][j]][i].push_back(edge(vec[i][j], k, 60));
            vv[vec[i][j]][k].push_back(edge(vec[i][j], i, 60));
          }
        }
      }
    }
//    for (int i = 0; i < (int)vec[0].size(); ++i) {
//      for(auto it: vv[vec[0][i]][0]) {
//        cout << it.num << ' ' << it.lvl << ' ' << it.cost << endl;
//      }
//    }
    priority_queue<edge> q;
    for (int i = 0; i < 100; ++i)
      clr(distt[i], '?');
    for (int i = 0; i < n; ++i) {
      if(vec[i][0] == 0) {
        q.push(edge(0, i, 0));
        distt[0][i] = 0;
      }
    }
    while (!q.empty()) {
      edge e = q.top();
      q.pop();
      if (e.cost > distt[e.num][e.lvl])
        continue;
      for (edge it : vv[e.num][e.lvl]) {
        if (distt[it.num][it.lvl] > distt[e.num][e.lvl] + it.cost) {
          distt[it.num][it.lvl] = distt[e.num][e.lvl] + it.cost;
          q.push(edge(it.num, it.lvl, distt[it.num][it.lvl]));
        }
      }
    }
    int ans = 1061109567;
    for (int i = 0; i < 5; ++i)
      ans = min(ans, distt[dist][i]);
    if (ans == 1061109567)
      cout << "IMPOSSIBLE\n";
    else
      cout << ans << '\n';
  }
  return 0;
}

