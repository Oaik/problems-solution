#include <iostream>

using namespace std;

string arr[1000];
int num = 0;
int dipNum = 0;

int main() {
	string input;
	cin.ignore();
	getline(cin, input);
	int inputLen = input.length();
	if (input[0] == '}') {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < inputLen; ++i) {
		if(input[i] == '}')
			break;
		else if ((int)input[i] > 96 && (int)input[i] < 123){
			arr[num] = input[i];
			++num;
		}
	}

	for (int j = 1; j < num; ++j) {
		for (int k = 0; k < j; ++k) {
			if (arr[j] == arr[k]) {
				++dipNum;
				break;
			}
		}
	}
	cout << num - dipNum;
}
