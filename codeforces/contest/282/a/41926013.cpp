#include <iostream>
#include <algorithm>
using namespace std;

char arr[150];

int main() {
	char ignored;
	int n = 0, x = 0;
	cin >> n;
	cin >> ignored;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		if(i > n-2)
			cin >> ignored;
		else {
			cin >> ignored;
			cin >> ignored;
		}
	}
	for (int j = 0; j < n; ++j) {
		if(arr[j] == '+')
			++x;
		else
			--x;
	}
	cout << x;
}
