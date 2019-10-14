#include <bits/stdc++.h>
using namespace std;

int main() {
	int i = 0;
	deque<char> result;
	result.push_back(' ');
	string inp;
	cin >> inp;
	for (; i < (int)inp.length(); ++i) {
		if ( (inp[i] == 'W') &&  inp[i + 1] == 'U' && inp[i + 2] == 'B' && (i < (int)inp.length() - 2) ) {
			i += 2;
			if ((result.back() != ' '))
				result.push_back(' ');
		} else {
			result.push_back(inp[i]);
		}
	}
	result.pop_front();
	for (auto j = result.begin(); j != result.end(); ++j)
		cout << *j;

}
