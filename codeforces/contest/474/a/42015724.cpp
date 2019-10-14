#include <bits/stdc++.h>
using namespace std;

char arr1[10] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p' };
char arr2[10] = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';'};
char arr3[10] = {'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/'};

int main() {
	int res = 0;
	char inp;
	string keyboard;
	cin >> inp >> keyboard;
	res = (inp == 'L') ? 1 : -1;
	for (int i = 0; i < (int)keyboard.length(); ++i) {
		for (int j = 0; j < 10; ++j) {
			if (arr1[j] == keyboard[i]) {
				cout << arr1[j + res];
			} else if (arr2[j] == keyboard[i]) {
				cout << arr2[j + res];
			} else if (arr3[j] == keyboard[i]) {
				cout << arr3[j + res];
			}
		}
	}
}
