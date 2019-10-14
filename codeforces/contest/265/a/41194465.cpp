#include <iostream>
using namespace std;

int main() {
	int pos = 0;
	string stones;
	cin >> stones;
	string instr;
	cin >> instr;
	int instrLen = instr.length();
	for (int i = 0; i < instrLen; ++i) {
		if (stones[pos] == instr[i])
			++pos;
	}
	cout << 1 + pos;
}
