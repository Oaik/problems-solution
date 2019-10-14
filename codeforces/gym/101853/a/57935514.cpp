#include <bits/stdc++.h>
using namespace std;
#define el      	'\n'
#define ft 			first
#define sd 			second
#define mp(x,y)  	make_pair((x),(y))
#define pb(x)    	push_back((x))
#define all(v)  	((v).begin()),((v).end())
#define sz(x)  		((int) (x).size())
#define clr(a,b)	memset(a,b,sizeof(a))
typedef long long ll;
void Yahia74() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin); //freopen("output.in", "w", stdout);
#endif
	cout << fixed << setprecision(0);
//	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
const int N = 1e6 + 5, M = 5e5 + 74, OO = 0x3f3f3f3f;

unordered_map<int, int> mp;
int arr[N];

int main() {
	Yahia74();
	int t, n, m;
	scanf("%d", &t);
	while(t--) {
		int diff = 0;
		mp.clear();
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i) {
			scanf("%d", arr + i);
			if(!mp[arr[i]] && arr[i] != 0)
				++diff;
			if(arr[i] != 0)
				++mp[arr[i]];
		}
		int type, pos, val;
		for (int i = 0; i < m; ++i) {
			scanf("%d", &type);
			if(type == 1) {
				scanf("%d %d", &pos, &val);
				--pos;
				--mp[arr[pos]];
				if(!mp[arr[pos]] && arr[pos] != 0)
					--diff;
				arr[pos] = val;
				++mp[val];
				if(mp[val] == 1 && val != 0)
					++diff;
			} else {
				printf("%d\n", diff);
			}
		}
	}
	return 0;
}
