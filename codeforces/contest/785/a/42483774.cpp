#include <bits/stdc++.h>
using namespace std;

int values[5] = { 4, 6, 8, 12, 20 };
string figures[5] = {"Tetrahedron", "Cube", "Octahedron", "Dodecahedron", "Icosahedron"};

int main() {
	int n, total = 0;
	string figure;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> figure;
		int index = std::distance(figures, std::find(figures, figures + 5, figure));
		total += values[index];
	}
	cout << total;
}

