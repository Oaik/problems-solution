#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string.h>
#include <queue>

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

void contest() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}

queue<int> elements;
bool visited[100000000] = {0};
int n, m;

int BFS(int n) {
	int dep = 0, sz = 1, curr = 0;
	elements.push(n), visited[n] = 1;
	while(true) {
		while(sz--) {
			curr = elements.front();
			if (curr == m)
				return dep;
			elements.pop();
			if (curr*2 < m * 2 && !visited[curr*2]) {
				visited[curr*2] = 1;
				elements.push(curr*2);
			}
			if (curr-1 > 0 && !visited[curr-1]) {
				visited[curr-1] = 1;
				elements.push(curr-1);
			}
		}
		dep++, sz = elements.size();
	}
	return dep;
}


int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> m;
	if (n == m) {
		cout << 0;
		return 0;
	}
	if (n > m) {
		cout << n - m;
		return 0;
	}
	clr(visited, 0);
	cout << BFS(n);
	return 0;
}

