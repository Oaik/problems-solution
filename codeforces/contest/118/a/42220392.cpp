#include <bits/stdc++.h>
using namespace std;

string vowels = "aoyeui";
vector<char> vec;

int main() {
	string input;
	cin >> input;
	transform(input.begin(), input.end(), input.begin(), ::tolower );
	for (int i = 0; i < (int)input.length(); ++i) {
		if ( !( vowels.find(input[i]) < vowels.length() ) ) {
			vec.push_back('.');
			vec.push_back(input[i]);
		}
	}
	for (auto it = vec.begin(); it != vec.end(); ++it)
		cout << *it;
}
