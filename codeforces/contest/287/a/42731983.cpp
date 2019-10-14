#include <iostream>
using namespace std;



int main() {
	int dx[3] = {0,1,1}, dy[3] = {1,0,1};
	char arr[4][4], curr;
	int counter = 1;
	for (int j = 0; j < 4; ++j)
		for (int i = 0; i < 4; ++i)
			cin >> arr[j][i];

	for (int j = 0; j < 3; ++j) {
			for (int i = 0; i < 3; ++i) {
				curr = arr[j][i];
				for (int k = 0; k < 3; ++k)
						if (arr[j+dx[k]][i+dy[k]] == curr)
							++counter;
				if (counter != 2) {
					cout << "YES";
					return 0;
				}
				counter = 1;
			}
		}
	cout << "NO";
}
