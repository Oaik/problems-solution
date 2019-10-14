#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<numeric>
#include<utility>
#include<functional>
#include<stdio.h>
#include<assert.h>
#include<memory.h>
#include<bitset>
#include <unordered_map>
using namespace std;

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define clr(arr, k) (memset(arr, k, sizeof(arr)))
#define lpv(i,a,n) 	for(int i=a;i<(int)n;i++)
#define ll long long

const double EPS = (1e-7);
const ll INF = 1e9;

int dcmp(double x, double y) {
	return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

ll n;

bool valid(ll x, ll y) {
	return x > 0 && x <= n && y > 0 && y <= n;
}


ll currx, curry, endx, endy;

set<pair<int, pair<int, int>>>q;
ll BFS(ll startx, ll starty) {
	q.clear();
	q.insert({0 ,{startx, starty}});
	int sz = q.size(), dep = 0;
//	bool ok = false;
	while(!q.empty()) {
		while(sz--) {
			auto curr = *q.begin();
			q.erase(q.begin());
			for (int i = 0; i < 8; ++i) {
				if (valid(curr.second.first + dx[i], curr.second.second + dy[i])) {
					if ( curr.second.first + dx[i] == endx && curr.second.second + dy[i] == endy) {
						return dep+1;
					}
					q.insert({dep ,{curr.second.first + dx[i], curr.second.second + dy[i]}});
				}
			}
		}
		sz = q.size(), dep++;
	}
	return INF;
}

void contest() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);
#endif
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	cin >> endx >> endy;
//	if (endx == 1 && endy == 1) {
//		cout << "White";
//		return 0;
//	}
//	if (endx == n && endy == n) {
//		cout << "Black";
//		return 0;
//	}
	if (endy <= n-endx+1) {
		cout << "White";
		return 0;
	} else {
		cout << "Black";
		return 0;
	}
//	ll white, black;
//	for (int i = 1; i <= n; ++i) {
//		for (int j = 0; j < 8; ++j) {
//			if (i + dx[j] == endx && i + dy[j] == endy) {
//				white = i;
//			}
//		}
//	}
//	for (int i = n; i > 0; --i) {
//			for (int j = 0; j < 8; ++j) {
//				if (i + dx[j] == endx && i + dy[j] == endy) {
//					black = (n-i)+1;
//				}
//			}
//		}
////	ll white = BFS(1, 1);
////	ll black = BFS(n, n);
//	if (white <= black)
//		cout << "White";
//	else
//		cout << "Black";
	return 0;
}