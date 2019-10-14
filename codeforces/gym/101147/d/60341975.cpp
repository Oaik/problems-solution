#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read(v) freopen(v, "rt", stdin);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e5 + 9, M = 1e6 + 1, OO = 1e9 + 1, MOD = 1e9 + 7;

ll NCR[21][21];

int main() {
//	fastIO
	read("popcorn.in")
	for (int i = 0; i < 21; ++i) {
		for (int j = 0; j <= i; ++j) {
			if(i == 0 || j == 0)
				NCR[i][j] = 1;
			else
				NCR[i][j] = NCR[i-1][j] + NCR[i-1][j-1];
		}
	}
	int t, N, M;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &N, &M);
		printf("%I64d\n", NCR[N][M]);
	}
	return 0;
}

