#include <bits/stdc++.h>
#define all(v)			((v).begin()), ((v).end())

using namespace std;

int main() {
	vector<char> chr;
	int n = 0;
	string str;
	cin >> n >> str;
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	for (int i = 0; i < n; ++i)
		chr.push_back(str[i]);
	sort(chr.begin(), chr.end());
	chr.erase(unique(chr.begin(), chr.end()), chr.end());
	if (chr.size() == 26)
		cout << "YES";
	else
		cout << "NO";
}
