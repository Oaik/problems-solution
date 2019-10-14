#include <iostream>

using namespace std;

int main() {
	int a = 0, b = 0, counter = 0;
	cin >> a >> b;
	int maxNum = max(a, b);
	for (int i = maxNum; i <= 6; ++i) {
		++counter;
	}
	if (counter == 0){
		cout << "0/1"; return 0;
	}
	int modo = (6 % counter);
	if (modo == 1){
		cout << counter << "/" << 6; return 0;
	}
	if (modo == 0){
		cout << 1 << "/" << 6/counter; return 0;
	}
	if (modo == 2) {
		cout << counter - 2 << "/" << 6/2; return 0;
	}
}
