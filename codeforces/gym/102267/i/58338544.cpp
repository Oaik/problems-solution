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
#define PI		acos(-1)
void teaaaaaaaaaaaaaaaaaaaaaaaaaaam() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin); //freopen("output.in", "w", stdout);
#endif
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
const int N = 2e5 + 5, M = 5e5 + 74, OO = 0x3f3f3f3f;

int arr[N];

int main() {
	teaaaaaaaaaaaaaaaaaaaaaaaaaaam();
	int n;
	string str;
	cin >> n >> str;
	stack<int> st;
	int it = str.find('(');
	string strr = str.substr(0, it);
	st.push(stoi(strr));
	arr[stoi(strr)] = 0;
	for (int i = max(it, 0); i < (int)str.size(); ++i) {
		if(str[i] == '(') {
			if(!strr.empty())
				st.push(stoi(strr));
			strr.clear();
		} else if(str[i] == ')') {
			if(!strr.empty()) {
				st.push(stoi(strr));
				strr.clear();
			}
			int tp = st.top();
			st.pop();
			arr[tp] = st.top();
		} else {
			strr += str[i];
		}
	}

	for (int i = 1; i <= n; ++i) {
		cout << arr[i] << ' ';
	}
	return 0;
}
