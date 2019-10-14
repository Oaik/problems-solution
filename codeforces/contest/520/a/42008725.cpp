#include <bits/stdc++.h>
using namespace std;
int main() {
	set<char> chr;
	int n = 0;
	string str;
	cin >> n >> str;
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	for (int i = 0; i < n; ++i)
		chr.emplace(str[i]);
	if (chr.size() == 26)
		cout << "YES";
	else
		cout << "NO";
}
