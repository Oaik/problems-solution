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

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define ll long long

const double EPS = (1e-7);
int dcmp(double x, double y) {
	return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}

using namespace std;
int mx[] = { 1, -1, 1, -1, 2, 2, -2, -2 };
int my[] = { 2, 2, -2, -2, -1, 1, -1, 1 };

int dis[9][9];

bool valid(int a, int b) {
	return a >= 0 && a < 8 && b >= 0 && b < 8;
}

int bfs(int a1, int a2, int b1, int b2) {
	queue<int> q;
	memset(dis, -1, sizeof(dis));
	dis[a1][a2] = 0;
	q.push(a1), q.push(a2);
	while (!q.empty()) {
		int x1 = q.front();
		q.pop();
		int x2 = q.front();
		q.pop();
		if (x1 == b1 && x2 == b2)
			return dis[x1][x2];
		for (int i = 0; i < 8; ++i) {
			int xr = x1 + mx[i];
			int xc = x2 + my[i];
			if (!valid(xr, xc)) continue;
			if (dis[xr][xc] == -1)
				dis[xr][xc] = dis[x1][x2] + 1, q.push(xr), q.push(xc);
		}
	}
	return -1;
}

int main() {
	char a1, a2, b1, b2;
	int move = 0;
	while (cin >> a1 >> a2 >> b1 >> b2) {
		move = bfs(a1 - 'a', a2 - '1', b1 - 'a', b2 - '1');
		printf("To get from %c%c to %c%c takes %d knight moves.\n", a1, a2, b1,
				b2, move);
	}
}

