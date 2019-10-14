#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define all(v)  	((v).begin()),((v).end())
#define sz(x)  		((int) (x).size())
#define clr(a,b)	memset(a,b,sizeof(a))

const double EPS = 1e-8;
int dcmp(double a, double b) {
	return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1;
}

void debug() {
	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);
}

deque<int> vecA, vecB;
vector<vector<int>> resA(100000), resB(100000);
int lps = 0;
bool simillar = false;

bool bfs(deque<int> dq, vector<vector<int>> res) {
	for(auto vec: res) {
		simillar = false;
		if(sz(vec) == sz(dq)) {
			lps = sz(vec);
			for (int i = 0; i < lps; ++i) {
				if(vec[i] == dq[i])
					simillar = true;
				else {
					simillar = false;
					break;
				}
			}
		}
		if(simillar)
			return true;
	}
	return false;
}

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n, k1, k2, a,b, k = 1;
	cin >> n >> k1;
	for (int i = 0; i < k1; ++i) {
		cin >> a;
		vecA.push_back(a);resA[0].push_back(a);
	}
	cin >> k2;
	for (int i = 0; i < k2; ++i) {
		cin >> b;
		vecB.push_back(b);resB[0].push_back(b);
	}
	while(!vecA.empty() && !vecB.empty()) {
		a = vecA.front();vecA.pop_front();
		b = vecB.front();vecB.pop_front();
		if(a > b) {
			vecA.push_back(b);
			vecA.push_back(a);
		} else {
			vecB.push_back(a);
			vecB.push_back(b);
		}
		if(bfs(vecA, resA) && bfs(vecB, resB)) {
			cout << -1;
			return 0;
		}
		for(auto it: vecA) {
			resA[k].push_back(it);
		}
		for(auto it: vecB) {
			resB[k].push_back(it);
		}
		++k;
	}
	if(vecA.empty())
		cout << k-1 << " " << 2;
	else
		cout << k-1 << " " << 1;
}
