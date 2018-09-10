#include <bits/stdc++.h>
using namespace std;

int r1,r2,c1,c2,d1,d2, start = 1, arr1[4];

int main() {
	cin >> r1>>r2>>c1>>c2>>d1>>d2;
	for (int i = 0; i < 10; ++i) {
		if (start > 9) {
			cout << "-1";
			break;
		}
		arr1[0] = start;

		int cell2 = r1 - start;
		if ( cell2 > 9 || cell2 <= 0 ) {
			++start;
			continue;
		}
		arr1[1] = cell2;

		int cell3 = c1 - start;
		if ( (cell3 > 9 || cell3 <= 0 || c1 != cell3 + start) || ( d2 != arr1[1] + cell3)) {
			++start;
			continue;
		}
		arr1[2] = cell3;

		int cell4 = d1-arr1[0];
		if (cell4 > 9 || cell4 <=0 || cell4 + arr1[2] != r2 || cell4 + arr1[1] != c2) {
			++start;
			continue;
		}
		arr1[3] = cell4;
		if ( count(arr1, arr1+4, arr1[0]) - 1 || count(arr1, arr1+4, arr1[1]) - 1 || count(arr1, arr1+4, arr1[2]) - 1 || count(arr1, arr1+4, arr1[3]) - 1) {
			cout << "-1";
			return 0;
		}
		cout << arr1[0] << " " << arr1[1] << "\n" << arr1[2] << " " << arr1[3];
		return 0;
	}
}

