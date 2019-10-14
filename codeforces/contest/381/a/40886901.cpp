#include <iostream>
using namespace std;
int main() {
	int num = 0,
		seCount = 0,
		diCount = 0;
	cin >> num;
	const int count = num;
	int arr[count];
	for (int i = 0; i < count; ++i) {
		cin >> arr[i];
	}
	int *leftPtr = arr;
	int *rightPtr = arr + num - 1;
	for (int k = 0; k < count; ++k) {
		if (k % 2 == 0) {
			if (*rightPtr > *leftPtr) {
				seCount += *rightPtr;
				--rightPtr;
			} else {
				seCount += *leftPtr;
				++leftPtr;
			}
		} else {
			if (*rightPtr > *leftPtr) {
				diCount += *rightPtr;
				--rightPtr;
			} else {
				diCount += *leftPtr;
				++leftPtr;
			}
		}
	}
	cout << seCount << " " << diCount;
	return 0;
}
