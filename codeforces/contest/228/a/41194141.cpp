#include <iostream>
using namespace std;

const int NUM = 4;
int arr[4];

int main() {
	int counter = 0;
	for (int i = 0; i < 4; ++i)
		cin >> arr[i];
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < i; ++j) {
			if (i == j) break;
			if (arr[i] == arr[j]) {
				++counter;
				break;
			}
		}
	}
	cout << counter;

}
