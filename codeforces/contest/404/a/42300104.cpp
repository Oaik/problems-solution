#include <bits/stdc++.h>
using namespace std;

int n = 0, toi = 0, toj = 0;
char cmpEdge, cmpCell;
bool edge = true, cell = true;
bool visited[300][300];
char arr[300][300];

bool valid (int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < n;
}

bool dfsEdge(int i, int j, int dir) {
	if (i == n) return 1;
	visited[i][j] = 1;
	if (arr[i][j] == cmpEdge && valid[i][j])
		dfsEdge(i+1, j+dir, dir);
	else {
		edge = false;
		cout << "NO";
		exit(EXIT_SUCCESS);
	}
	return edge;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cin >> arr[i][j];
	}
	cmpEdge = arr[0][0];
	cmpCell = arr[0][1];
	if (cmpEdge == cmpCell) {
		cout << "NO";
		return 0;
	}
	dfsEdge(0,0, 1);
	visited[n/2][n/2] = 0;
	dfsEdge(0,n-1, -1);
	for (int o = 0; o < n; ++o) {
		for (int var = 0; var < n; ++var) {
			if (!visited[o][var] && arr[o][var] != cmpCell) {
				cout << "NO";
				return 0;
			}
		}
	}
	if (edge && cell)
		cout << "YES";
	else
		cout << "NO";
}
