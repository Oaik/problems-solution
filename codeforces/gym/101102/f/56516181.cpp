#include <bits/stdc++.h>
using namespace std;
#define el        '\n'
#define ft      first
#define sd      second
#define mp(x,y)   make_pair((x),(y))
#define pb(x)     push_back((x))
#define all(v)    ((v).begin()),((v).end())
#define sz(x)     ((int) (x).size())
#define clr(a,b)  memset(a,b,sizeof(a))
typedef long long ll;

void Yahia74() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "r", stdin); //freopen("output.in", "w", stdout);
#endif
}

const int N = 5e5 + 74, M = 5e5 + 74, OO = 0x3f3f3f3f;
int app[26];
char s[200000];

int main() {
  Yahia74();
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    clr(app, '?');
    for (int i = 0;s[i]; i++) {
      if (app[s[i] - 'a'] > 1e9)
        app[s[i] - 'a'] = i;
    }
    int let1 = -1, let2 = 28, ans;
    for (int i = 0; i < 26 && let1 == -1; i++) {
      ans = app[i];
      if(ans > 1e9)
        continue;
      for (int j = i + 1; j < 26; j++) {
        if (app[j] < ans) {
          let1 = i;
          let2 = j;
          ans = app[j];
        }
      }
    }
    if (let1 == -1)
      printf("%s\n", s);
    else {
      char sm = let1 + 'a', bg = let2 + 'a';
      for (int i = 0;s[i]; i++) {
        if (s[i] == sm)
          printf("%c", bg);
        else if (s[i] == bg)
          printf("%c", sm);
        else
          printf("%c", s[i]);
      }
      puts("");
    }
  }
  return 0;
}
