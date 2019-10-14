#include <iostream>
using namespace std;
int main() {
	int size = 0, count = 0;
	cin >> size;
	int arr1[size], arr2[size];
	for (int k = 0; k < size; ++k)
		cin >> arr1[k] >> arr2[k];
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (i == j)
				continue;
			if(arr1[i] == arr2[j])
				++count;
		}
	}
	cout << count;
	return 0;
}