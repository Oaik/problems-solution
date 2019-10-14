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
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
const int N = 5e5 + 74, M = 5e5 + 74, OO = 0x3f3f3f3f;

vector<char> arr = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};
int freq[26];

int main() {
	Yahia74();
	int n;
	string str, rev;
	cin >> n;
	while(n--) {
		cin >> str;
		clr(freq, 0);
		bool can = 1;
		int m = str.size();
		for (int u = 0; u < m; ++u)
			++freq[str[u] - 'A'];
		for (int u = 0; u < 26; ++u) {
			if(find(all(arr), u + 'A') == arr.end()) {
				if(freq[u]) {
					can = 0;
					cout << "no\n";
					break;
				}
			}
		}
		if(!can)
			continue;
		rev = str;
		reverse(all(rev));
		if(rev == str) {
			cout << "yes\n";
		} else {
			cout << "no\n";
		}
	}
	return 0;
}
