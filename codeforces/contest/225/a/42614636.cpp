#include <bits/stdc++.h>
using namespace std;


int main() {
	bool faces[7] = {0,0,0,0,0,0};
	int a, b, t, head;
	bool found;
	cin >> t >> head;
	for (int i = 0; i < t; ++i) {
		memset(faces, 0, sizeof(faces));
		cin >> a >> b;
		faces[head] = 1,faces[a] = 1, faces[b] = 1, faces[7-a] = 1, faces[7-b] = 1;
		for (int j = 1; j <= 6; ++j) {
			found = false;
			if (!faces[j] && head + j == 7) {
				head = j, found = true;
				break;
			}
		}
		if (!found) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}

