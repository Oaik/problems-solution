#include <iostream>
using namespace std;
int main() {
	int a = 0, b = 0, c = 0, d = 0, result = 0;
	cin >> a >> b >> c >> d;
	string input;
	cin >> input;
	int inputLen = input.length();
	for (int i = 0; i < inputLen; ++i) {
		if(input[i] == '1')
			result += a;
		else if (input[i] == '2')
			result += b;
		else if (input[i] == '3')
			result += c;
		else
			result += d;
	}
	cout << result;
}