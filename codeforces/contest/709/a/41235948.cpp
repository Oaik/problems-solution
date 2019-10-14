#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int num= 0, maxSize= 0, waste= 0, current= 0, counter = 0;
	int sum = 0;
	cin >> num >> maxSize >> waste;
	for (int i = 0; i < num; ++i) {
		cin >> current;
		if (current <= maxSize)
			sum += current;
		if (sum > waste) {
			++counter;
			sum = 0;
		}
	}
	cout << counter;
	return 0;
}
