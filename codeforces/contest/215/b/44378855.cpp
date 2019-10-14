#include <cstdio>
#include <algorithm>


int main() {
  int n; std::scanf("%d", &n);

  int r1 = 0;
  for (int i = 0; i < n; ++i) {
    int x; std::scanf("%d", &x);
    r1 = std::max(r1, x);
  }

  int m; std::scanf("%d", &m);

  int p1 = 0;
  for (int i = 0; i < m; ++i) {
    int y; std::scanf("%d", &y);
    p1 = std::max(p1, y);
  }

  int k; std::scanf("%d", &k);

  int p2 = std::numeric_limits<int>::max();
  for (int i = 0; i < k; ++i) {
    int y; std::scanf("%d", &y);
    p2 = std::min(p2, y);
  }

  int a, b; std::scanf("%d%d", &a, &b);

  std::printf("%f\n", r1 * std::sqrt(static_cast<double>(p1 * b) / (p2 * a + p1 * b)));
  return 0;
}