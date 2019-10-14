#include <bits/stdc++.h>

using namespace std;
const int N = 25;
int dp[1 << (N - 1)], x[N], y[N], length[N][N], n;

void print(int mask) {
  if (mask == (1 << n) - 1)
    return;
  for (int i = 0; i < n; i++) {
    if (!(mask & (1 << i))) {
      for (int j = i; j < n; j++) {
        if (!(mask & (1 << j))) {
          if (dp[mask] == length[N - 1][i] + length[i][j] + length[j][N - 1] + dp[mask | (1 << i) | (1 << j)]) {
            printf("%d ", i + 1);
            if (j != i)
              printf("%d ", j + 1);
            printf("0 ");
            print(mask | (1 << i) | (1 << j));
            break;
          }
        }
      }
      break;
    }
  }
  return;
}

int solve(int mask) {
  if (mask == (1 << n) - 1)
    return 0;
  if (dp[mask])
    return dp[mask];
  int ans = 1E9;
  for (int i = 0; i < n; i++) {
    if (!(mask & (1 << i))) {
      for (int j = i; j < n; j++) {
        if (!(mask & (1 << j))) {
          ans = min(ans, solve(mask | (1 << i) | (1 << j)) + length[N - 1][i] + length[i][j] + length[j][N - 1]);
        }
      }
      break;
    }
  }
  return dp[mask] = ans;
}

int main() {
  scanf("%d %d", &x[N - 1], &y[N - 1]);
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d %d", &x[i], &y[i]);
  for (int i = 0; i < n; i++) {
    length[N - 1][i] = length[i][N - 1] = (x[i] - x[N - 1]) * (x[i] - x[N - 1]) + (y[i] - y[N - 1]) * (y[i] - y[N - 1]);
    for (int j = i + 1; j < n; j++)
      length[i][j] = length[j][i] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
  }
  printf("%d\n", solve(0));
  printf("0 ");
  print(0);
  return 0;
}
