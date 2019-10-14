#include <bits/stdc++.h>
using namespace std;

int arr[100];

void isGuy(int arr[], int limit , int inp) {
	for (int j = 0; j < limit; ++j) {
		cin >> inp;
		arr[inp] = 1;
	}
}

int main() {
	int n = 0, p = 0, a = 0, pInput = 0, aInput = 0;
	cin >> n >> p;
	isGuy(arr, p ,pInput);
	cin >> a;
	isGuy(arr, a ,aInput);
	for (int i = 1; i <= n; ++i) {
		if (arr[i] != 1) {
			cout << "Oh, my keyboard!";
			return 0;
		}
	}
	cout << "I become the guy.";
	return 0;
}
