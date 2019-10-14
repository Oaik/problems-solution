#include <bits/stdc++.h>
using namespace std;

int values[5] = { 4, 6, 8, 12, 20 };
vector<string> figures = {"Tetrahedron", "Cube", "Octahedron", "Dodecahedron", "Icosahedron"};

int main() {
	int n, total = 0;
	string figure;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> figure;
		auto it = std::find(figures.begin(), figures.end(), figure);
		auto index = std::distance(figures.begin(), it);
		total += values[index];
	}
	cout << total;
}

