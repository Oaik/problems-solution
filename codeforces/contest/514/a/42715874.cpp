#include <iostream>
using namespace std;


int main() {
	char a;
	int num;
	cin >> a;
	num = a - '0';
	if (9-num < num && 9-num > 0)
		cout << 9-num;
	else
		cout << num;
	while(cin >> a) {
		num = a - '0';
		if (9-num < num && 9-num >= 0)
			cout << 9-num;
		else
			cout << num;
	}
}
